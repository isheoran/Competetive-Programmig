#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

struct Segtree {
    vector<vector<int>>tree;
    Segtree (const vector<int>&a) {
        int n = sz(a);
        tree.resize(4*n);
        build(a,0,n-1,1);
    }

    void merge(int node) {
        int i = 0,j=0;
        for(;i<sz(tree[2*node]) and j<sz(tree[2*node+1]);) {
            if(tree[2*node][i] < tree[2*node+1][j]) {
                tree[node].push_back(tree[2*node][i]);
                i++;
            }
            else {
                tree[node].push_back(tree[2*node+1][j]);
                j++;
            }
        }
        while(i<sz(tree[2*node])) {
            tree[node].push_back(tree[2*node][i]);
            i++;
        }
        while(j<sz(tree[2*node+1])) {
            tree[node].push_back(tree[2*node+1][j]);
            j++;
        }
    }
    
    void build(const vector<int>&a,int st,int en,int node) {
        if(st == en) {
            tree[node].push_back(a[st]);
            return;
        }
        int mid = (st+en)/2;
        build(a,st,mid,2*node);
        build(a,mid+1,en,2*node+1);
        merge(node);
    }

    int query(int l,int r,int st,int en,int k,int node=1) {
        if(st>r or en<l) return 0;
        if(st>=l and en<=r) {
            return (int)(tree[node].end() - upper_bound(all(tree[node]),k));
        }
        int mid = (st+en)/2;
        return query(l,r,st,mid,k,2*node) + query(l,r,mid+1,en,k,2*node+1);
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    input(a);
    Segtree tree(a);
    int q;
    cin>>q;
    while(q--) {
        int i,j,k;
        cin>>i>>j>>k;
        cout<<tree.query(i-1,j-1,0,n-1,k)<<"\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
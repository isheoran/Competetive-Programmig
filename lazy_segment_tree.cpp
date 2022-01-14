#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n"; 

struct Segtree {
    vector<int>tree,lazy;
    Segtree (string &a) {
        int n = sz(a);
        tree.resize(4*n);
        lazy.assign(4*n,-1);
        build(a,0,n-1,1);
    }
    
    void build(string &a,int st,int en,int node) {
        if(st == en) {
            tree[node] = a[st]-'0';
            return;
        }
        int mid = (st+en)/2;
        build(a,st,mid,2*node);
        build(a,mid+1,en,2*node+1);
        tree[node] =tree[2*node+1]+tree[2*node];
    }
    
    int query(int l,int r,int st,int en,int node=1) {
        int mid = (st+en)/2;
        if(lazy[node]!=-1 and st!=en) {
            if(lazy[node]) {
                lazy[node] = -1;
                lazy[2*node] = lazy[2*node+1] = 1LL;
                tree[2*node] = mid-st+1;
                tree[2*node+1] = en-mid;
            }
            else {
                lazy[node] = -1;
                lazy[2*node] = lazy[2*node+1] = 0;
                tree[2*node] = tree[2*node+1] = 0;
            }
        }
        if(st>r or en<l or l>r) return 0;
        if(st>=l and en<=r) return tree[node];
        return query(l,r,st,mid,2*node)+query(l,r,mid+1,en,2*node+1);
    }

    void update(int l,int r,int value,int st,int en,int node=1) {
        int mid = (st+en)/2;
        if(lazy[node]!=-1 and st!=en) {
            if(lazy[node]) {
                lazy[node] = -1;
                lazy[2*node] = lazy[2*node+1] = 1LL;
                tree[2*node] = mid-st+1;
                tree[2*node+1] = en-mid;
            }
            else {
                lazy[node] = -1;
                lazy[2*node] = lazy[2*node+1] = 0;
                tree[2*node] = tree[2*node+1] = 0;
            }
        }
        if(l>r or st>r or en<l) return;
        if(st==en) {
            tree[node] = value;
            return;
        }
        if(st>=l and en<=r) {
            lazy[node] = value;
            tree[node] = (en-st+1)*value;
            return;
        } 
        update(l,r,value,st,mid,2*node);
        update(l,r,value,mid+1,en,2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1]; 
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    string s,f;
    cin>>s>>f;
    vector<pair<int,int>>qry;
    for(int i=0;i<q;i++) {
        int l,r;
        cin>>l>>r;
        qry.push_back({l-1,r-1});
    }
    reverse(all(qry));
    Segtree T(f);
    for(auto &u:qry) {
        int cnt = T.query(u.first,u.second,0,n-1);
        if((u.second-u.first+1)%2==0 and cnt==(u.second-u.first+1)/2) {
            cout<<"NO\n";
            return;
        }
        if(cnt<=(u.second-u.first+1)/2) {
            T.update(u.first,u.second,0,0,n-1);
        }
        else {
            T.update(u.first,u.second,1,0,n-1);
        }
    }
    for(int i=0;i<n;i++) {
        if(T.query(i,i,0,n-1)!=s[i]-'0') {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    vector<vector<int>>tree;
    vector<bool>lazy;
    Segtree (const string &s) {
        int n = s.size();
        tree.assign(4*n,vector<int>(4,0));
        lazy.assign(4*n,false);
        build(s,0,n-1,1);
    }

    void merge(int node) {
        tree[node][1] = tree[2*node+1][1] + tree[2*node][1];
        tree[node][0] = tree[2*node+1][0] + tree[2*node][0];
        tree[node][2] = max(tree[2*node][0]+tree[2*node+1][2],tree[2*node][2]+tree[2*node+1][1]);
        tree[node][3] = max(tree[2*node][1]+tree[2*node+1][3],tree[2*node][3]+tree[2*node+1][0]);
    }

    void build(const string &s,int st,int en,int node) {
        if(st==en) {
            if(s[st]=='4') tree[node][0] = 1;
            else tree[node][1] = 1;
            tree[node][2] = tree[node][3] = 1;
            return;
        }
        int mid = (st+en)/2;
        build(s,st,mid,2*node);
        build(s,mid+1,en,2*node+1);
        merge(node);
    }
    
    void update(int l,int r,int st,int en,int node=1) {
        if(lazy[node]) {
            swap(tree[node][0],tree[node][1]);
            swap(tree[node][2],tree[node][3]);
            lazy[node] = false;
            if(st!=en) {
                lazy[2*node] = !lazy[2*node];
                lazy[2*node+1] = !lazy[2*node+1];
            }
        }
        if(en<l or st>r) return ;
        if(st>=l and en<=r) {
            swap(tree[node][0],tree[node][1]);
            swap(tree[node][2],tree[node][3]);
            if(st!=en) {
                lazy[2*node] = !lazy[2*node];
                lazy[2*node+1] = !lazy[2*node+1];
            }
            return;
        }
        int mid = (st+en)/2;
        update(l,r,st,mid,2*node);
        update(l,r,mid+1,en,2*node+1);
        merge(node);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    Segtree t(s);
    while(m--) {
        string tmp;
        cin>>tmp;
        if(tmp=="count") {
            cout<<t.tree[1][2]<<"\n";
        }
        else {
            int l,r;
            cin>>l>>r;
            t.update(l-1,r-1,0,n-1);
        }
    }

    return 0;
}
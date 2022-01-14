#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(v,p) memset(v,p,sizeof(v))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n"; 

struct Node {
    int up,x;
    
    Node() {
        up = -1;
        x = 0;
    }
    Node (int type,int value) {
        up = type;
        x = value;
    }
    //up == -1 means nothing to do and 0 means add and 1 means set
    Node operator+ (Node &o) {
        Node X;
        if(o.up) {
            X = o;
        }
        else {
            if(up==-1) {
                X = o;
            }
            else if(up==0) {
                X.x = x + o.x;
                X.up = 0;
            }
            else {
                X.up = 1;
                X.x = x + o.x;
            }
        }
        return X;
    }
};

struct Segtree {
    vector<int>tree;
    vector<Node>lazy;
    Segtree (vector<int>&a) {
        int n = sz(a);
        tree.resize(4*n);
        lazy.resize(4*n);
        build(a,0,n-1,1);
    }
    
    void build(vector<int>&a,int st,int en,int node) {
        if(st == en) {
            tree[node] = a[st];
            return;
        }
        int mid = (st+en)/2;
        build(a,st,mid,2*node);
        build(a,mid+1,en,2*node+1);
        tree[node] =tree[2*node+1]+tree[2*node];
    }
    
    int query(int l,int r,int st,int en,int node=1) {
        int mid = (st+en)/2;
        if(st!=en and lazy[node].up!=-1) {
            if(lazy[node].up) {
                lazy[2*node] = lazy[2*node] + lazy[node];
                lazy[2*node+1] = lazy[2*node+1] + lazy[node];
                tree[2*node] = lazy[node].x*(mid-st+1);
                tree[2*node+1] = lazy[node].x*(en-mid);
                lazy[node] = Node();
            }
            else {
                lazy[2*node] = lazy[2*node] + lazy[node];
                lazy[2*node+1] = lazy[2*node+1] + lazy[node];
                tree[2*node] += lazy[node].x*(mid-st+1);
                tree[2*node+1] += lazy[node].x*(en-mid);
                lazy[node] = Node();
            }
        }
        if(st>r or en<l) return 0;
        if(st>=l and en<=r) return tree[node];
        return query(l,r,st,mid,2*node)+query(l,r,mid+1,en,2*node+1);
    }

    void update(int l,int r,int type,int value,int st,int en,int node=1) {
        int mid = (st+en)/2;
        if(st!=en and lazy[node].up!=-1) {
            if(lazy[node].up) {
                lazy[2*node] = lazy[2*node] + lazy[node];
                lazy[2*node+1] = lazy[2*node+1] + lazy[node];
                tree[2*node] = lazy[node].x*(mid-st+1);
                tree[2*node+1] = lazy[node].x*(en-mid);
                lazy[node] = Node();
            }
            else {
                lazy[2*node] = lazy[2*node] + lazy[node];
                lazy[2*node+1] = lazy[2*node+1] + lazy[node];
                tree[2*node] += lazy[node].x*(mid-st+1);
                tree[2*node+1] += lazy[node].x*(en-mid);
                lazy[node] = Node();
            }
        }
        if(r<st or l>en) return;
        if(st>=l and en<=r) {
            if(type) {
                tree[node] = value*(en-st+1);
            }
            else {
                tree[node] += value*(en-st+1);
            }
            Node tmp = Node(type,value);
            lazy[node] = lazy[node] + tmp;
            return;
        }
        update(l,r,type,value,st,mid,2*node);
        update(l,r,type,value,mid+1,en,2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>x(n);
    input(x);
    x.insert(x.begin(),0);
    Segtree T(x);
    while(q--) {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1) {
            int x;
            cin>>x;
            T.update(a,b,0,x,0,n);
        }
        else if(t==2) {
            int x;
            cin>>x;
            T.update(a,b,1,x,0,n);
        }
        else {
            cout<<T.query(a,b,0,n)<<"\n";
        }
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
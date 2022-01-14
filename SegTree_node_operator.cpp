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

struct node {
    int a,b,c,ab,bc,abc;

    node () {
        a = b = c = ab = bc = abc = 0;
    }

    node (char ch) {
        a = b = c = ab = bc = abc = 0;
        if(ch=='a') a = 1;
        else if(ch=='b') b = 1;
        else c = 1;
    }

    node operator+ (node &o) {
        node x;
        x.a = a + o.a;
        x.b = b + o.b;
        x.c = c + o.c;
        x.ab = min(a+o.ab,ab+o.b);
        x.bc = min(b+o.bc,bc+o.c);
        x.abc = min({a+o.abc,ab+o.bc,abc+o.c});
        return x;
    }
};

struct Segtree {
    vector<node>tree;
    Segtree (string &s) {
        int n = sz(s);
        tree.resize(4*n);
        build(s,0,n-1,1);
    }
    
    void build(string &s,int st,int en,int nd) {
        if(st == en) {
            tree[nd] = node(s[st]);
            return;
        }
        int mid = (st+en)/2;
        build(s,st,mid,2*nd);
        build(s,mid+1,en,2*nd+1);
        tree[nd] =tree[2*nd]+tree[2*nd+1];
    }
    
    void update(int pos,char c,int st,int en,int nd=1) {
        if(pos<st or pos>en) return;
        if(st == en) {
            tree[nd] = node(c);
            return;
        }
        int mid = (st+en)/2;
        update(pos,c,st,mid,2*nd);
        update(pos,c,mid+1,en,2*nd+1);
        tree[nd] =tree[2*nd]+tree[2*nd+1];
    }
};

void solve() {
    int n,q;
    string s;
    cin>>n>>q>>s;
    Segtree T(s);
    while(q--) {
        int pos;
        char c;
        cin>>pos>>c;
        T.update(pos-1,c,0,n-1);
        cout<<T.tree[1].abc<<"\n";
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
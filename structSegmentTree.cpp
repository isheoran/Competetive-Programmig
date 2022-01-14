#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define fill0(dp) memset(dp,0,sizeof(dp))
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

struct Segtree {
    vector<int>tree;
    Segtree (vector<int>&a) {
        int n = sz(a);
        tree.resize(4*n);
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
        tree[node] = __gcd(tree[2*node+1],tree[2*node]);
    }
    
    int query(int l,int r,int st,int en,int node=1) {
        if(st>r or en<l) return 0;
        if(st>=l and en<=r) return tree[node];
        int mid = (st+en)/2;
        return __gcd(query(l,r,st,mid,2*node),query(l,r,mid+1,en,2*node+1));
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    input(a);
    if(n==1)
    {
        cout<<"1\n";
        return;
    }
    for(int i=0;i<n-1;i++) a[i] = abs(a[i+1]-a[i]);
    a.pop_back();
    Segtree seg(a);
    int j=0,ans=1;
    for(int i=0;i<n-1;i++)
    {
        while(j<=i and seg.query(j,i,0,n-2)<2) j++;
        ans = max(ans,i-j+2);
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
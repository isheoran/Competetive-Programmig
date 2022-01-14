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
const int nmm = 2e5+2;
vector<int>a(nmm),tree(4*nmm);

void build(int node ,int l,int r)
{
    if(l == r) 
    {
        tree[node] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node,int st,int en, int l,int r)
{
    if(en<l or st>r) return 0;
    if(st>=l and en<=r) return tree[node];
    int mid = (st+en)/2;
    return query(2*node,st,mid,l,r) + query(2*node+1,mid+1,en,l,r);
}

void update(int node,int st,int en,int pos,int value)
{
    if(st == en) 
    {
        tree[node] = value;
        return;
    }
    int mid = (st+en)/2;
    if(pos<=mid) update(2*node,st,mid,pos,value);
    else update(2*node+1,mid+1,en,pos,value);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    while(q--)
    {
        int q1,q2,q3;
        cin>>q1>>q2>>q3;
        if(q1 == 1) update(1,0,n-1,q2-1,q3);
        else cout<<query(1,0,n-1,q2-1,q3-1)<<"\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
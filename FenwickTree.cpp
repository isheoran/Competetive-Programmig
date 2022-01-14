#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fill0(dp) memset(dp,0,sizeof(dp))
const int nmm = 1e5+1;
int n,q,a[nmm],bit[nmm];

void update(int idx,int x)
{
    for(;idx<n;idx+=idx&(-idx))
    {
        bit[idx]+=x;
    }
}

void buidBIT()
{
    fill0(bit);
    for(int i=1;i<=n;i++)
    {
        update(i,a[i]);
    }
}

int query(int idx)
{
    int ans=0;
    while(idx>0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    buidBIT();
    while(q--)
    {
        int x,y,z;
        cin>>x;
        if(x==1)
        {
            int sum;
            cin>>sum;
            cout<<a[sum+1]<<"\n";
            update(sum+1,-a[sum+1]);
        }
        else if(x==2)
        {
            cin>>y>>z;
            update(y+1,z);
        }
        else
        {
            cin>>y>>z;
            cout<<query(z+1)-(y>0 ? query(y+1) : 0)<<"\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    for(int i=1;i<=testcases;i++)
    {
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
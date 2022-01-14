#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkshtra(vector<vector<pair<ll,ll>>>&adj,vector<ll>&d,ll s,ll n)
{
    for(ll i = 0;i<n;i++) d[i] = (ll)(1e18+2);
    priority_queue<pair<ll,ll>>q;
    vector<bool>processed(n);
    q.push({0,s});
    d[s]=0;
    while(!q.empty())
    {
        ll a = q.top().second;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u : adj[a])
        {
            ll b = u.first,l = u.second;
            if(d[b]>d[a]+l)
            {
                d[b]=d[a]+l;
                q.push({-d[b],b});
            }
        }
    }
}

void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<ll,ll>>> adj(n);
    while (m--)
    {
        ll a, b, l;
        cin >> a >> b >> l;
        if(a==b) continue;
        adj[a].push_back(make_pair(b,l));
        adj[b].push_back(make_pair(a,l));
    }
    vector<ll>d(n);
    while(q--)
    {
        ll s;
        cin>>s;
        dijkshtra(adj,d,s,n);
        ll cnt = 0,dist = 0;
        for(int i=0;i<n;i++)
        {
            if(d[i]>=dist and d[i]<(ll)(1e15))
            {
                if(d[i]==dist) cnt++;
                else
                {
                    dist=d[i];
                    cnt=1;
                }
            }
        }
        cout<<dist<<" "<<cnt<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int testcases = 1;
    //cin>>testcases;
    while (testcases--)
        solve();
    return 0;
}
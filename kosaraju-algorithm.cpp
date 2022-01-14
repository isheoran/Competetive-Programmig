#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
vector<int>comp,order;
vector<bool>visited; 
vector<vector<int>>adj,rev_adj;

void dfs1(int s)
{
    if(visited[s]) return;
    visited[s]=true;
    for(auto u:adj[s]) dfs1(u);
    order.push_back(s);
}

void dfs2(int s)
{
    if(visited[s]) return;
    visited[s]=true;
    for(auto u:rev_adj[s]) dfs2(u);
    comp.push_back(s);
}

void solve()
{
    int n,cst=0,ways=1;
    cin>>n;
    vector<int>cost(n);
    input(cost);
    int m;
    cin>>m;
    adj.resize(n+1);
    rev_adj.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    visited.assign(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) dfs1(i);
    }
    reverse(all(order));
    for(int i=0;i<=n;i++) visited[i]=false;
    for(auto u:order)
    {
        if(!visited[u])
        {
            comp.clear();
            dfs2(u);
            int mncost=1e18;
            int cnt=0;
            for(auto x:comp)
            {
                mncost=min(mncost,cost[x-1]);
            }
            for(auto x:comp)
            {
                if(mncost == cost[x-1]) cnt++;
            }
            cst+=mncost;
            ways = ways*cnt%mod;
        }
    }
    cout<<cst<<" "<<ways<<"\n";
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
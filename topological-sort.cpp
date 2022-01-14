#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1);
    vector<int>order;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        order.push_back(x);
        for(auto u:adj[x])
        {
            indegree[u]--;
            if(indegree[u]==0) q.push(u);
        }
    }
    if(sz(order)==n)
    {
        print(order);
    }
    else cout<<"IMPOSSIBLE\n";
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
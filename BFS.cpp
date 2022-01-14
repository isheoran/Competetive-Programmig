#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<bool>visited(n+1);
    vector<int>distance(n+1);
    vector<vector<int>>adj(n+1);
    while (m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    distance[1]=0;
    visited[1]=true;
    q.push(1);
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(auto u:adj[s])
        {
            if(visited[u]) continue;
            visited[u]=true;
            distance[u]=distance[s]+1;
            q.push(u);
        }
    }
    cout<<distance[n]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
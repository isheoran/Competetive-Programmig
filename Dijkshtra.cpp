#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    while(m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<bool>processed(n+1);
    vector<int>d(n+1);
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++) d[i] = INT_MAX;
    priority_queue<pair<int,int>>q;
    parent[1]=-1;
    q.push({0,1});
    d[1]=0;
    while(!q.empty())
    {
        int s = q.top().second;
        q.pop();
        if(processed[s]) continue;
        processed[s]=true;
        for(auto u : adj[s])
        {
            int b = u.first, w = u.second;
            if(d[b]>d[s]+w)
            {
                parent[b]=s;
                d[b]=d[s]+w;
                q.push({-d[b],b});
            }
        }
    }
    if(processed[2])
    {
        cout<<d[2]<<"\n";
        vector<int>path;
        for(int i=2;i!=-1;i=parent[i]) path.push_back(i);
        reverse(path.begin(),path.end());
        for(auto i:path) cout<<i<<" ";
    }
    else cout<<"Not Possible\n";
}    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
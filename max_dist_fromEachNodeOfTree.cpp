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
vector<vector<int>>adj;
vector<int>d1,d2;

void dfs1(int s,int p) {
    for(auto u:adj[s]) {
        if(u!=p) {
            d1[u] = d1[s] + 1;
            dfs1(u,s);
        }
    }
}

void dfs2(int s,int p) {
    for(auto u:adj[s]) {
        if(u!=p) {
            d2[u] = d2[s] + 1;
            dfs2(u,s);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    adj.resize(n+1);
    d1.resize(n+1);
    d2.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int e1=1,e2=1,dist=-1;
    d1[1] = 0;
    dfs1(1,-1);
    for(int i=1;i<=n;i++) {
        if(d1[i]>dist) {
            dist = d1[i];
            e1 = i;
        }
    }
    d1[e1] = 0;
    dfs1(e1,-1);
    dist = -1;
    for(int i=1;i<=n;i++) {
        if(dist<d1[i]) {
            dist = d1[i];
            e2 = i;
        }
    }
    d2[e2] = 0;
    dfs2(e2,-1);
    for(int i=1;i<=n;i++) {
        cout<<max(d1[i],d2[i])<<" ";
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
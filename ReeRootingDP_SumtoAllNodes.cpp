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
vector<int>childs,dsum;
int n;

void dfs1(int s,int p) {
    for(int u:adj[s]) {
        if(u!=p) {
            dfs1(u,s);
            childs[s] += childs[u]+1;
            dsum[s] += dsum[u] + childs[u] + 1;
        }
    }
}

void dfs2(int s,int p) {
    dsum[s] = dsum[p]- 2*childs[s]-2+n;
    for(auto u:adj[s]) {
        if(u!=p) {
            dfs2(u,s);
        }
    }
}

void solve() {
    cin>>n;
    adj.resize(n+1);
    childs.resize(n+1);
    dsum.resize(n+1);
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,-1);
    for(int u:adj[1]) {
        dfs2(u,1);
    }
    for(int i=1;i<=n;i++) cout<<dsum[i]<<" ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(v,p) memset(v,p,sizeof(v))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el ; cout << "\n"; 
vector<vector<int>>adj,adj_rev;
vector<bool>used;
stack<int>order;
vector<int>component;

void dfs1(int s) {
    used[s] = true;
    for(auto u:adj[s]) {
        if(!used[u]) dfs1(u);
    }
    order.push(s);
}

void dfs2(int s) {
    used[s] = true;
    component.push_back(s);
    for(auto u:adj_rev[s]) {
        if(!used[u]) {
            dfs2(u);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    input(a);
    a.insert(a.begin(),0);
    adj.resize(n+1);
    adj_rev.resize(n+1);
    int m;
    cin>>m;
    while(m--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    used.assign(n+1,false);
    int min_cost = 0,ways = 1;
    for(int i=1;i<=n;i++) {
        if(!used[i]) dfs1(i);
    }
    used.assign(n+1,false);
    while(!order.empty()) {
        int s = order.top();
        order.pop();
        if(used[s]) continue;
        component.clear();
        dfs2(s);
        int mn = inf;
        for(auto u:component) mn = min(mn,a[u]);
        min_cost += mn;
        int cnt = 0;
        for(auto u:component) cnt += a[u]==mn;
        ways = ways*cnt%mod;
    }
    cout<<min_cost<<" "<<ways;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
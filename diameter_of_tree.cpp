#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(v,p) memset(v,p,sizeof(v))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n"; 
vector<vector<int>>adj;
vector<bool>vis;

auto diameter(int root,int n) {
    int tmp = root;
    vector<int>d(n+1),parent(n+1,-1);
    
    auto bfs = [&](int s) {
        vector<bool>processed(n+1,false);
        queue<int>q;
        q.push(s);
        d[s] = 0;
        processed[s] = true;
        while(!q.empty()) {
            s = q.front();
            q.pop();
            vis[s] = true;
            for(auto u:adj[s]) {
                if(processed[u]) continue;
                processed[s] = true;
                d[u] = d[s] + 1;
                q.push(u);
                parent[u] = s;
            }
        }
    };

    bfs(root);
    for(int i=1;i<=n;i++) {
        if(d[i] > d[root]) root = i;
    }
    bfs(root);
    int dia = *max_element(all(d));
    int nxt = -1;
    for(int i=0;i<=n;i++) {
        if(d[i]==dia) nxt = i;
    }
    while(d[nxt]!=dia/2) {
        nxt = parent[nxt];
    }
    return make_pair(dia,(dia/2 ? nxt : tmp));
}

void solve() {
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    while(m--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>>pr;
    vis.assign(n+1,false);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            pr.push_back({i,diameter(i,n).first});
        }
    }
    sort(all(pr),[&](auto u,auto v) {
        return u.second > v.second;
    });
    vector<pair<int,int>>edges;
    for(int i=1;i<sz(pr);i++) {
        int root1 = diameter(pr[0].first,n).second,root2 = diameter(pr[i].first,n).second;
        adj[root1].push_back(root2);
        adj[root2].push_back(root1);
        edges.push_back({root1,root2});
        //cout<<root1<<" "<<root2<<"\n";
    }
    cout<<diameter(1,n).first<<"\n";
    for(auto u:edges) {
        cout<<u.first<<" "<<u.second<<"\n";
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
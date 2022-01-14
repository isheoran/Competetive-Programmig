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

struct LCA {
    vector<vector<int>>st;
    vector<int>parent,level;

    LCA (vector<vector<int>>&adj) {
        int n = sz(adj);
        int k = log2(n)+2;
        st.assign(n,vector<int>(k,-1));
        parent.assign(n,-1);
        level.assign(n,0);
        dfs(adj,1,-1);
        for(int i=1;i<=n-1;i++) st[i][0] = parent[i];
        build(n-1);
    }

    void dfs(vector<vector<int>>&adj,int s,int p) {
        parent[s] = p;
        for(auto u:adj[s]) {
            if(u!=p) {
                level[u] = level[s] + 1;
                dfs(adj,u,s);
            }
        }
    }

    void build(int n) {
        for(int j=1;(1<<j)<=n;j++) {
            for(int i=1;i<=n;i++) {
                if(st[i][j-1]!=-1) {
                    st[i][j] = st[st[i][j-1]][j-1];
                }
            }
        }
    }

    int lca(int a,int b,int n) {
        if(level[a] < level[b]) swap(a,b);
        int dist = level[a] - level[b];
        while(dist) {
            int raise_by = log2(dist);
            a = st[a][raise_by];
            dist -= (int)(1<<raise_by);
        }
        
        if(a == b) return a;

        int k = log2(n)+1;
        for(int j=k;j>=0;j--) {
            if(st[a][j]!=-1 and st[a][j]!=st[b][j]) {
                a = st[a][j];
                b = st[b][j];
            }
        }
        return parent[a];
    }

    int kth_ancestor(int a,int k) {
        while(k) {
            int raise_by = log2(k);
            a = st[a][raise_by];
            k -= (int)(1LL<<raise_by);
            if(a == -1) return a;
        }
        return a;
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int u;
        cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    LCA tree(adj);
    while(q--) {
        int a,b;
        cin>>a>>b;
        cout<<tree.kth_ancestor(a,b)<<"\n";
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
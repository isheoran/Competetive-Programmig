#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(998244353)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(v,p) memset(v,p,sizeof(v))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n"; 

struct two_sat {
    int n;
    vector<vector<int>>g,gr;
    vector<int>comp,topological_order;
    vector<bool>ans,vis;

    two_sat(){}

    two_sat(int _n) {
        n = _n;
        g.resize(2*n+1);
        gr.resize(2*n+1);
        comp.resize(2*n+1);
        ans.resize(n+1);
        vis.resize(2*n+1);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    void dfs(int s) {
        vis[s] = true;
        for(const auto &u:g[s]) {
            if(!vis[u]) dfs(u);
        }
        topological_order.push_back(s);
    }

    void assign_ssc(int s,int id) {
        comp[s] = id;
        vis[s] = true;
        for(const auto &u:gr[s]) {
            if(!vis[u]) assign_ssc(u,id);
        }
    }

    bool is_satisfiable() {
        for(int i=1;i<=2*n;i++) {
            if(!vis[i]) dfs(i);
        }
        for(int i=0;i<=2*n;i++) vis[i] = false;
        reverse(all(topological_order));
        int id = 1;
        for(const auto &u:topological_order) {
            if(!vis[u]) {
                assign_ssc(u,id++);
            }
        }

        for(int i=1;i<=n;i++) {
            if(comp[i]==comp[i+n]) return false;
            ans[i] = (comp[i]>comp[i+n]);
        }
        return true;
    }
};

void solve() {
    int n,m,x,y;
    cin>>n>>m;
    two_sat G(m);
    for(int i=0;i<n;i++) {
        char ch1,ch2;
        cin>>ch1>>x>>ch2>>y;
        if(ch1=='-') x+=m;
        if(ch2=='-') y+=m;
        G.add_edge(x>m ? x-m:x+m,y);
        G.add_edge(y>m ? y-m : y+m,x);
    }

    if(!G.is_satisfiable()) cout<<"IMPOSSIBLE\n";
    else {
        for(int i=1;i<=m;i++) {
            cout<<(G.ans[i] ? "+ " : "- ");
            //cout<<G.comp[i]<<" ";
        }
        //print(G.topological_order);
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
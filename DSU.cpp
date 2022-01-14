#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill0(dp) memset(dp,0,sizeof(dp))
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

struct DSU {
    vector<int>parent,sizz;

    DSU(int n) {
        for(int i=0;i<=n;i++) parent.push_back(i);
        sizz.assign(n+1,1);
    }
    
    int find_set(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int u,int v) {
        u = find_set(u);
        v = find_set(v);

        if(v == u) return;

        if(sizz[u] > sizz[v]) swap(u,v);
        parent[u] = v;
        sizz[v] += sizz[u];
    }
};

void solve() {
    int n,m1,m2;
    cin>>n>>m1>>m2;
    DSU forest1(n),forest2(n);

    for(int i=0;i<m1;i++) {
        int u,v;
        cin>>u>>v;
        forest1.union_set(u,v);
    }

    for(int i=0;i<m2;i++) {
        int u,v;
        cin>>u>>v;
        forest2.union_set(u,v);
    }

    vector<pair<int,int>>ans;

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(forest2.find_set(i)!=forest2.find_set(j) and forest1.find_set(i)!=forest1.find_set(j)) {
                ans.push_back({i,j});
                forest2.union_set(i,j);
                forest1.union_set(i,j);
            }
        }
    }

    cout<<sz(ans)<<"\n";
    for(auto &u:ans) cout<<u.first<<" "<<u.second<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
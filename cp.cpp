#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

const int nmm = 1e6+10;
int spf[nmm],phi[nmm];

vector<int> divisors(int n) {
    if(n==0) return {};
    vector<int> d[2];
    d[0] = {n};
    while(spf[n]!=1) {
        int di=spf[n],cnt=0;
        int mxdi = di;
        while(spf[n] == di) {
            cnt++;
            n/=di;
        }
        for(int j=1;j<cnt;j++) mxdi *= di;
        while(cnt>=0) {
            for(auto u:d[0]) {
                d[1].push_back(u/mxdi);
            }
            mxdi/=di;
            cnt--;
        }
        swap(d[0],d[1]);
        d[1].clear();
    }
    return d[0];
}

void Eular_totient_function() {
    for(int i=0;i<nmm;i++) spf[i] = i;
    for(int i=2;i*i<=nmm;i++) {
        if(spf[i]==i) {
            for(int j=i*i;j<nmm;j+=i) {
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    for(int i=1;i<nmm;i++) {
        phi[i] = i;
        int n = i;
        while(spf[n]!=1) {
            int f = spf[n];
            phi[i] = phi[i]*(f-1)/f;
            while(n%f==0) n/=f;
        }
    }
}

void sieve() {
    for(int i=0;i<nmm;i++)spf[i]=i;
    for(int i=2;i*i<=nmm;i++) {
        if(spf[i]==i) {
            for(int j=i*i;j<nmm;j+=i) {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

struct Combo {
    vector<int>fact,invfact;

    Combo(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for(int i=1;i<n;i++) {
            fact[i] = fact[i-1]*i%mod;
            invfact[i] = binpow(fact[i],mod-2);
        }
    }

    int binpow(int a,int b) {
        if(b<0) return 0;
        int res = 1;
        while(b>0) {
            if(b & 1) res = res*a%mod;
            a = a*a%mod;
            b>>=1;
        }
        return res;
    }
    
    int binomial(int n,int r) {
        if(n<0 or r<0 or n<r) return 0;
        return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
    }

};

int no_of_divisors(int n)
{
    int cnt=0,pre=0,res=1;
    while(spf[n]!=1)
    {
        int x=spf[n];
        n/=spf[n];
        if(cnt==0)
        {
            pre=x;
            cnt++;
        }
        else 
        {
            if(x==pre) cnt++;
            else
            {
                res*=(cnt+1);
                cnt=1;
                pre=x;
            }
        }
    }
    res*=(cnt+1);
    return res;
}

int binpow(int a,int b) {
    if(b<0) return 0;
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

struct Segtree {
    vector<int>tree;
    Segtree (vector<int>&a) {
        int n = sz(a);
        tree.resize(4*n);
        build(a,0,n-1,1);
    }
    
    void build(vector<int>&a,int st,int en,int node) {
        if(st == en) {
            tree[node] = a[st];
            return;
        }
        int mid = (st+en)/2;
        build(a,st,mid,2*node);
        build(a,mid+1,en,2*node+1);
        tree[node] =tree[2*node+1]+tree[2*node];
    }
    
    int query(int l,int r,int st,int en,int node=1) {
        if(st>r or en<l) return 0;
        if(st>=l and en<=r) return tree[node];
        int mid = (st+en)/2;
        return query(l,r,st,mid,2*node)+query(l,r,mid+1,en,2*node+1);
    }

    void update(int pos,int value,int st,int en,int node=1) {
        if(pos<st or pos>en) return;
        if(st == en) {
            tree[node] = value;
            return;
        }
        int mid = (st+en)/2;
        update(pos,value,st,mid,2*node);
        update(pos,value,mid+1,en,2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
};

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

struct BIT {
    vector<int>tree;
    int n;

    BIT(int n) {
        this->n = n;
        tree.resize(n);
    }

    int query(int r) {
        int res = 0;
        while(r>=0) {
            res += tree[r];
            r = (r&(r+1))-1;
        }
        return res;
    }

    void update(int i,int val) {
        while(i<n) {
            tree[i] += val;
            i = (i|(i+1));
        }
    }
};

void solve()
{
    sieve();
    int n;
    cin>>n;
    int ans=1,temp=1;
    for(int i=2;i<=n;i++)
    {
        temp=ans;
        temp+=no_of_divisors(i);
        ans+=temp;
        ans%=mod;
        temp%=mod;
    }
    cout<<temp%mod<<"\n";
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

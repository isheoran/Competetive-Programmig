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

void solve() {
    int n;
    cin>>n;
    BIT T(n);
    for(int i=0;i<n;i++) {
        T.update(i,1);
    }
    string s,t;
    cin>>s>>t;
    queue<int>q[26];
    for(int i=0;i<n;i++) {
        q[s[i]-'a'].push(i);
    }

    int ans = inf,calc=0;
    for(int i=0;i<n;i++) {
        int cur = inf;
        for(int j=0;j<(int)(t[i]-'a');j++) {
            if(q[j].empty()) continue;
            cur = min(cur,T.query(q[j].front()));
        }
        if(cur<inf) ans = min(ans,calc+cur-1LL);
        if(q[t[i]-'a'].empty()) break;
        calc += T.query(q[t[i]-'a'].front())-1LL;
        T.update(q[t[i]-'a'].front(),-1);
        q[t[i]-'a'].pop();
    }

    cout<<(ans==inf ? -1 : ans)<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
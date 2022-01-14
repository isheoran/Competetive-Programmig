#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

void solve() {
    string p,t;
    cin>>p>>t;
    int n = sz(t),m = sz(p);
    vector<int>pre(m);
    //pre[i] represents the length of longest string which is suffix as well as
    //prefix of [t0---ti]
    pre[0] = 0;
    for(int i=1;i<m;i++) {
        int j = pre[i-1];
        while(j>0 and p[i]!=p[j]) {
            j = pre[j-1];
        }
        if(p[j]==p[i]) j++;
        pre[i] = j;
    }
    int cnt = 0;
    for(int i=0,j=0;i<n;i++) {
        while(j>0 and t[i]!=p[j]) j = pre[j-1];
        if(t[i]==p[j]) j++;
        if(j==m) {
            cnt++;
            j = pre[j-1];
        }
    }
    cout<<cnt<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
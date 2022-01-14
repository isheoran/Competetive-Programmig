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
        int res = 1;
        while(b) {
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

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    Combo ncr(n+5);
    vector<int>a(n);
    input(a);
    sort(all(a));
    int ans = 0;
    for(int i=0;i<n;i++) {
        int l=i+1;
        int r = upper_bound(all(a),a[i]+k)-a.begin();
        (ans += ncr.binomial(r-l,m-1))%=mod;
    }
    cout<<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
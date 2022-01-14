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
const int nmm = 1e6+1;
int fac[nmm];

void factorial() {
    fac[0] = 1;
    for(int i=1;i<nmm;i++) fac[i] = fac[i-1]*i%mod;
}

int binpow(int a,int b) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = res*a%mod;
        }
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

int binomial(int a,int b) {
    int res = fac[a]*binpow(fac[b],mod-2)%mod;
    res = res*binpow(fac[a-b],mod-2)%mod;
    return res;
}

void solve() {
    int a,b;
    cin>>a>>b;
    cout<<binomial(a,b)<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    factorial();
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
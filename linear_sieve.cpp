#include <iostream>
#include <vector>
#define sz(s) (int)s.size()
using namespace std;
const int nmm = 5e6+50;
int cnt[nmm],a[nmm];
long long dp[nmm];
vector<int>primes;
bool is_composite[nmm];

void linear_sieve() {
    for(int i=0;i<nmm;i++) {
        is_composite[i] = false;
    }
    for(int i=2;i<nmm;i++) {
        if(!is_composite[i]) primes.push_back(i);
        for(int j=0;j<sz(primes) and primes[j]*i<nmm;j++) {
            is_composite[i*primes[j]] = true;
            if(i%primes[j]==0) break;
           
        }
    }
}

long long max(long long x,long long y) {
    if(x > y) return x;
    return y;
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=2;i<=nmm;i++) {
        for(int j=i;j<nmm;j+=i) {
            cnt[i] += a[j];
        }
    }
    for(long long int i=nmm-10;i>1;i--) {
        dp[i] = cnt[i]*i;
        for(auto u:primes) {
            if(u*i>=nmm) break;
            dp[i] = max(dp[i],dp[i*u]+i*(cnt[i]-cnt[i*u]));
        }
    }
    long long int ans = 0;
    for(long long int i=nmm-1;i>1;i--) {
        ans = max(ans,dp[i]+n-cnt[i]);
    }
    cout<<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    linear_sieve();
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
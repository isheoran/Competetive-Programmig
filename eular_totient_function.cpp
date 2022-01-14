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
const int nmm = 1e6+10;
int spf[nmm],phi[nmm];

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

void solve() {
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i++) {
       ans += phi[i]*(n/i)*(n/i);
    }
    cout<<2*ans-n*n<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    Eular_totient_function();
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
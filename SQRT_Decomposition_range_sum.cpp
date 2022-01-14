#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n"; 

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>a(n),block(n);
    input(a);
    int lnth = sqrtl(n)+1;
    for(int i=0;i<n;i++) {
        block[i/lnth] += a[i];
    }
    while(q--) {
        int t,l,r;
        cin>>t>>l>>r;
        l--,r--;
        if(t==1) {
            block[l/lnth] += r+1-a[l];
            a[l] = r+1;
        }
        else {
            int ans = 0;
            if(l/lnth==r/lnth) {
                for(int i=l;i<=r;i++) ans += a[i];
            }
            else {
                int left = l/lnth+1,right=r/lnth-1;
                for(int i=l;i<left*lnth;i++) ans += a[i];
                for(int i=left;i<=right;i++) ans += block[i];
                for(int i=lnth*(right+1);i<=r;i++) ans += a[i];
            }
            cout<<ans<<"\n";
        }
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
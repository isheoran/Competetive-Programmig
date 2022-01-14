#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 
int a,b,d,k,dp[12][12][2];
vector<int>num;

int f(int pos,int cnt,bool small) {
    if(cnt>k) return 0;
    if(pos==sz(num)) {
        if(cnt==k) return true;
        return false;
    }
    if(dp[pos][cnt][small]!=-1) return dp[pos][cnt][small];
    int res = 0;
    if(small) {
        for(int i=0;i<10;i++) {
            if(i!=d) res += f(pos+1,cnt,small);
            else res += f(pos+1,cnt+1,small);
        }
    }
    else {
        for(int i=0;i<10;i++) {
            if(i<num[pos]) {
                if(i==d) res += f(pos+1,cnt+1,true);
                else res += f(pos+1,cnt,true);
            } 
            else if(i==num[pos]) {
                if(i==d) res += f(pos+1,cnt+1,small);
                else res += f(pos+1,cnt,small);
            }
        }
    }
    return dp[pos][cnt][small] = res;
}

void solve() {
    cin>>a>>b>>d>>k;
    memset(dp,-1,sizeof(dp));
    int tmp = b;
    while(tmp) {
        num.push_back(tmp%10);
        tmp/=10;
    }
    reverse(all(num));
    int ans = f(0,0,false);
    num.clear();
    memset(dp,-1,sizeof(dp));
    tmp = a-1;
    while(tmp) {
        num.push_back(tmp%10);
        tmp/=10;
    }
    reverse(all(num));
    ans -= f(0,0,false);
    cout<<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    for(int i=1;i<=testcases;i++) {
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
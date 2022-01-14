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

vector<vector<int>> mul(vector<vector<int>>&a,vector<vector<int>>&b) {
    vector<vector<int>>tmp(2,vector<int>(2,0));
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            tmp[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j];
            tmp[i][j]%=mod;
        }
    }
    return tmp;
}

vector<vector<int>> binpow(vector<vector<int>>&a,int b) {
    vector<vector<int>>res(2,vector<int>(2,0));
    res[0][0] = res[1][1] = 1;
    while(b) {
        if(b & 1) res = mul(res,a);
        a = mul(a,a);
        b>>=1;
    }
    return res;
}

int fibonacci(int n) {
    vector<vector<int>>a(2,vector<int>(2,1));
    a[1][1] = 0;
    a = binpow(a,n-1);
    return a[0][0];
}

void solve() {
    int n;
    cin>>n;
    if(n == 0) cout<<"0\n";
    else cout<<fibonacci(n)<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
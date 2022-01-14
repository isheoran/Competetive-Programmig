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

vector<int> robin_carp(string &a,string &b)
{
    // b is pattern.
    const int p = 31;
    int n=sz(a),m=sz(b);
    vector<int>pre_hsh(n+1,0),p_pow(max(n,m));
    p_pow[0] = 1;
    for(int i=1;i<max(n,m);i++) p_pow[i] = p_pow[i-1]*p%mod;
    for(int i=0;i<n;i++)
    {
        pre_hsh[i+1] = (pre_hsh[i] + p_pow[i]*((int)(a[i]-'a'+1)))%mod;
    }
    int b_hsh = 0;
    for(int i=0;i<m;i++) (b_hsh += p_pow[i]*((int)(b[i]-'a'+1)))%=mod;
    vector<int>occurences;
    for(int i=0;i+m-1<n;i++)
    {
        int c_hsh = (pre_hsh[i+m]-pre_hsh[i]+mod)%mod;
        if(c_hsh == b_hsh*p_pow[i]%mod) occurences.push_back(i+1);
    }
    return occurences;
}

void solve()
{
    string a,b;
    cin>>a>>b;
    vector<int>occurences = robin_carp(a,b);
    if(sz(occurences))
    {
        cout<<sz(occurences)<<"\n";
        print(occurences);
    }
    else cout<<"Not Found\n";
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}
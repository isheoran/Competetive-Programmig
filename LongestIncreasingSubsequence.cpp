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

void solve()
{
    int n,x;
    cin>>n;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        auto it = lower_bound(all(ans),x);
        if(it == ans.end()) ans.push_back(x);
        else *it = x;
    }
    cout<<sz(ans)<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
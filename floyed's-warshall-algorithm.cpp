#include<iostream>
#define int long long
const int inf = 1e16;
using namespace std;

int mp[401][401];
int dp[401][401][401];

int min(int i,int j)
{
    return i < j ? i : j;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<401;i++)
    {
        for(int j=0;j<401;j++)
        {
            mp[i][j] = (i==j ? 0 : inf);
        }
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a][b] = c;
    }
    
    for(int i=0;i<401;i++){
        for(int j=0;j<401;j++){
            for(int k=0;k<401;k++){
                dp[i][j][k] = inf;
            }
        }
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
                dp[i][j][k] = mp[i][j];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)
            {
                ans += dp[i][j][k] < inf ? dp[i][j][k] : 0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
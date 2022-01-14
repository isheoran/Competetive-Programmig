#include<bits/stdc++.h>
using namespace std;
#define input(v) for (auto &i : v) cin >> i;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vector<ll>b(n+2);
        input(b);sort(b.begin(),b.end());
        ll s = 0;
        for(int i=0;i<n;i++) s+=b[i];
        if(s==b[n])
        {
            for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<"\n";
        }
        else
        {
            ll x = s+b[n]-b[n+1];
            bool ans=0;
            ll pos=0;
            for(int i=0;i<n+1;i++)
            {
                if(b[i]==x)
                {
                    ans=1;
                    pos=i;
                }
            }
            if(ans)
            {
                for(int i=0;i<n+1;i++)
                {
                    if(i==pos) continue;
                    else cout<<b[i]<<" ";
                }cout<<"\n";
            }
            else cout<<"-1\n";
        }
    }
    
}
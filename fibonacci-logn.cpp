#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

struct matrix
{
    int a1,a2,b1,b2;
};

matrix matrixmultiply(matrix m,matrix n)
{
    matrix ans;
    ans.a1=m.a1*n.a1%mod+m.a2*n.b1%mod;
    ans.a2=m.a1*n.a2%mod+m.a2*n.b2%mod;
    ans.b1=m.b1*n.a1%mod+m.b2*n.b1%mod;
    ans.b2=m.b1*n.a2%mod+m.b2*n.b2%mod;
    return ans;
}

matrix binpow(matrix m,int b)
{
    matrix res;
    res.a1=1,res.a2=0,res.b1=0,res.b2=1;
    while(b)
    {
        if(b&1) res=matrixmultiply(res,m);
        m=matrixmultiply(m,m);
        b>>=1;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    matrix p;
    p.a1=0,p.a2=1,p.b1=1,p.b2=1;
    matrix res=binpow(p,n);
    cout<<res.b1<<"\n";
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
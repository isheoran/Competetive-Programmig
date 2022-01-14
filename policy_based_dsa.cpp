#include <bits/stdc++.h>
using namespace std;
#define sz(s) (int)(s.size())

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int q;
    cin>>q;
    oset<pair<int,int>>s;
    while(q--)
    {
        int c,t;
        cin>>c>>t;
        if(c==1)
        {
            s.insert({t,1});
        }
    }
    s.erase(s.lower_bound({2,0}));
    cout<<sz(s);
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
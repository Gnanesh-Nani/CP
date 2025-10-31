#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20
#define MOD 1000000007
#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)


int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int ans = 1;
        for(int i = 0; i < n; i++ ){
            ans=(ans*2)%MOD;
        }
        cout<<ans;
    }
    return 0;
}

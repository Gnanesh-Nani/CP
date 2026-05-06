#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 15

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

void solve() {

};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int d;
        cin>>d;
        float r = d/2.0;
        float area = (3.141592653589793)*r*r;
        cout<<area<<endl;
    }
    return 0;
}

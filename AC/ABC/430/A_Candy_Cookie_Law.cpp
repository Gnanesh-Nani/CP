#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define set_double_precision cout << fixed << setprecision(DOUBLE_PRECISION)

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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c >= a && d < b)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}

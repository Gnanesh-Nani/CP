#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define set_double_precision cout << fixed << setprecision(DOUBLE_PRECISION)

void solve(int n)
{
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2)
        {
            n = n * 3 + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    cout << 1 << endl;
};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        solve(n);

    }
    return 0;
}

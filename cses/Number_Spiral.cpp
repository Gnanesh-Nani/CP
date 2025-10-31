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
    cin >> t;
    while (t--)
    {
        int i, j, n;
        cin >> i >> j;
        i--;
        j--;
        n = max(i, j);
        int num = 1 + n * (n + 1);
        if (i == j)
        {
            cout << num << endl;
            continue;
        }
        int ans;
        if (n % 2) //odd diagonal
        {
            if (j < n) // on left
            {
                ans = num + (n - j);
            }
            else
            {
                ans = num - (n - i);
            }
        }
        else
        {
            if (j < n)
            {
                ans = num - (n - j);
            }
            else
            {
                ans = num + (n - i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

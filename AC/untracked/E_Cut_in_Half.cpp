#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        priority_queue<double> PQ;
        for (int i = 0; i < n; i++)
        {
            double s;
            cin >> s;
            PQ.push(s);
        }

        for (int i = 0; i < k; i++)
        {
            double s = PQ.top();
            PQ.pop();
            double half = s / 2;
            PQ.push(half);
            PQ.push(half);
        }
        while (PQ.size() >= x)
            PQ.pop();

        cout << fixed << setprecision(20) << PQ.top() << endl;
    }
    return 0;
}

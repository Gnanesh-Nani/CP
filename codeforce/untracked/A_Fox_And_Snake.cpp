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
    string str;
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector<char>> arr(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2)
            {
                arr[i][j] = '.';
            }
            else
                arr[i][j] = '#';
        }
    }

    int is_right = true;
    for (int i = 1; i < m;i = i + 2)
    {
        if (is_right)
            arr[i][n-1] = '#';
        else
            arr[i][0] = '#';
        is_right = !is_right;
    }

    for (auto v : arr)
    {
        for (char i : v)
            cout << i;
        cout << endl;
    }
    return 0;
}

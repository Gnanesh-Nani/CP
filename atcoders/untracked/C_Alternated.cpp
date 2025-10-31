#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int f_swapped(string str,int n)
{
    int cnt = 0;
    int last_mis_pos_a = -1;
    int last_mis_pos_b = -1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        { // 0 - 2 - 4 should be B now
            if (str[i] == 'B')
                continue;
            else
            {
                if (last_mis_pos_b == -1)
                {
                    last_mis_pos_a = i;
                    continue;
                }
                cnt += (i - last_mis_pos_b);
                last_mis_pos_b = -1;
            }
        }
        else
        { // 1 - 3 - 5 should be A now
            if (str[i] == 'A')
                continue;
            else
            {
                if (last_mis_pos_a == -1)
                {
                    last_mis_pos_b = i;
                    continue;
                }
                cnt += (i - last_mis_pos_a);
                last_mis_pos_a = -1;
            }
        }
    }
    return cnt;
}

int f(string str,int n)
{
    int cnt = 0;
    int last_mis_pos_a = -1;
    int last_mis_pos_b = -1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        { // 0 - 2 - 4
            if (str[i] == 'A')
                continue;
            else
            {
                if (last_mis_pos_a == -1)
                {
                    last_mis_pos_b = i;
                    continue;
                }

                cnt += (i - last_mis_pos_a);
                // cout << "i : lmp  " << i << " " << last_mis_pos_a << " cnt + " << (i - last_mis_pos_a) << endl;
                last_mis_pos_a = -1;
            }
        }
        else
        {
            if (str[i] == 'B')
            {
                continue;
            }
            else
            {
                if (last_mis_pos_b == -1)
                {
                    last_mis_pos_a = i;
                    continue;
                }

                cnt += (i - last_mis_pos_b);
                // cout << "i : lmp  " << i << " " << last_mis_pos_b << " cnt + " << (i - last_mis_pos_b) << endl;
                last_mis_pos_b = -1;
            }
        }
    }
    return cnt;
}


int32_t main()
{
    fastio;
    int n;
    string str;
    cin >> n >> str;

    n = str.length();
    
    cout << min(f(str,n),f_swapped(str,n));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

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
        int n;
        cin>>n;
        int Xor = 0;
        for(int i = 1; i < n ;i++){
            int num;
            cin>>num;
            Xor ^= i;
            Xor ^= num;
        }
        Xor ^= n;
        cout<<Xor;
    }
    return 0;
}

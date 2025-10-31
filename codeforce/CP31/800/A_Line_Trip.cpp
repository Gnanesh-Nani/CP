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
    cin >> t;
    while (t--)
    {
        int n,x;
        cin>> n >> x;
        int maxi = 0;
        int prev = 0;
        for(int i = 0; i < n;i++){
            int temp;
            cin >> temp;
            if(i == 0) {
                maxi = max(maxi,temp);
            } else {
                maxi = max(maxi,abs(temp - prev));
            }
            prev = temp;
        }
        maxi = max(maxi, 2 * abs(x - prev));
        cout<<maxi<<endl;
    }
    return 0;
}

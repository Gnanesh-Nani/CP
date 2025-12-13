#include <bits/stdc++.h>
using namespace std;

//constants and shits
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
        vector<int> arr(3,0);
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr.rbegin(),arr.rend());
        cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    }
    return 0;
}

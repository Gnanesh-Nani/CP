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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i =0; i < n;i++)
            cin>>arr[i];
        int sum = 0;
        for(int i = 1; i < n;i++){
            sum = sum + abs(arr[i] - arr[i-1]);
        }
        // cout<<sum<<endl;
        int ans = LONG_LONG_MAX;
        ans = min(ans,sum - abs(arr[0] - arr[1]));
        ans = min(ans,sum - abs(arr[n-1] - arr[n-2]));

        for(int i = 1; i < n-1;i++){
            ans = min(ans,sum - abs(arr[i] - arr[i-1]) - abs(arr[i] - arr[i+1]) + abs(arr[i-1] - arr[i+1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}

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
        int n,temp;
        cin>>n;
        vector<int> arr;
        for(int i =0;i < n;i++){
            cin>>temp;
            arr.push_back(temp);
        }

        int maxi = 0;
        for(int i =0;i < n;i++){
            int sum = 0;
            for(int j = i;j < n;j++){
                sum += arr[j];
                maxi = max(maxi,sum/(j-i+1));
            }
        }

        cout<<maxi<<endl;
    }
    return 0;
}

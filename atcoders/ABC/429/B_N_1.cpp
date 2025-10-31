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
        int n,m;
        cin>>n>>m;
        vector<int> arr;
        int sum = 0;

        for(int i = 0; i < n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
            sum += temp;
        }

        for(int i:arr){
            if((sum - i) == m){
                cout<<"Yes"<<endl;
                return 0;
            }
        }

        cout<<"No"<<endl;
    }
    return 0;
}

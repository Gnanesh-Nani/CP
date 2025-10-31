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
        if(n == 1)
        {
            cout<<1;
            return 0;
        } else if(n == 2 || n == 3)
        {
            cout<<"NO SOLUTION";
            return 0;
        }
        vector<int> arr(n);
        int num = 1;
        for(int i = 1; i < n;i=i+2){
            arr[i] = num;
            num++;
        }
        for(int i = 0; i < n;i=i+2){
            arr[i] = num;
            num++;
        }


        for(int i:arr)
            cout<<i<<" ";
    }
    return 0;
}

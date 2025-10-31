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
        int n,k;
        cin >> n>>k;
        vector<int> arr;
        for(int i =0; i < n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        if(k >= 2)
            cout<<"YES"<<endl;
        else{
            bool isSorted = true;
            for(int i = 1; i < n;i++){
                if(arr[i-1] > arr[i])
                    isSorted = false;
            }
            if(isSorted)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}

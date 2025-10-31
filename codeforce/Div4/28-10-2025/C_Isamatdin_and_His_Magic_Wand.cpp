#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

void printArr(vector<int> &arr) {
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
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
        vector<int> arr;
        int even = 0;
        int odd = 0;
        for(int i=0; i < n;i++){
            int temp;cin>>temp;
            even += (temp%2==0);
            odd += (temp%2);
            arr.push_back(temp);
        }
        
        if(even == 0 || odd == 0){
            printArr(arr);
        } else {
            sort(arr.begin(),arr.end());
            printArr(arr);
        }
    }
    return 0;
}

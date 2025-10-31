#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20
#define int long long
#define all(x) (x).begin(), (x).end()

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define set_double_precision cout << fixed << setprecision(DOUBLE_PRECISION)

bool isPrime(int num){
    for(int i = 2;i < num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

bool check(int p,vector<int> &arr) {
    for(int i:arr){
        if(__gcd(p,i) == 1)
            return true;
    }
    return false;
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
        for(int i = 0; i < n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }

        int p = 2;
        while(true){
            if(isPrime(p) && check(p,arr))
            {
                cout<<p<<endl;
                break;
            }
            p++;
        }

    }
    return 0;
}

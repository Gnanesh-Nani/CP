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
        int k;
        cin>>k;
        for(int i = 0;i < k;i++){
            int n = i+1;
            int x = n*n;
            cout<< ((x)*(x-1))/2 - 2*2*(n-1)*(n-2)<<endl;
        }
    }
    return 0;
}

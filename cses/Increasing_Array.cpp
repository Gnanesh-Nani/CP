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
        int num;
        cin>>num;
        int last = num;
        int cnt = 0;
        for(int i = 1; i < n;i++){
            cin>>num;
            if(num < last){
                cnt += (last - num);
            } else {
                last = num;
            }
        }
        cout<<cnt;
    }
    return 0;
}

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
        string str;
        cin>>str;

        char last = 'N';

        int ans = 0;
        int cnt = 0;
        for(char c:str){
            if(c == last){
                cnt++;
            } else {
                last = c;
                cnt = 1;
            }
            ans = max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}

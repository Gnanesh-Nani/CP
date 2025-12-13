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
        int n = str.length();
        sort(str.begin(),str.end());
        for(int i = 0; i < n;i++){
            if(str[i]!='0'){
                swap(str[0],str[i]);
                break;
            }
        }
        cout<<str<<endl;
    }
    return 0;
}

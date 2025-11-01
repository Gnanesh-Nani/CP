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
    // fix it
    while (t--)
    {
        int n,A,B;
        cin>>n>>A>>B;
        string str;
        cin>>str;

        int L =0;
        int R = 0;
        int a = 0;
        int b = 0;
        int cnt = 0;
        while(R < n) {
            a += (str[R]=='a');
            b += (str[R]=='b');
            while(L < n && b >= B){
                a -= (str[L]=='a');
                b -= (str[L]=='b');
                L++;
            } 
            if(a >= A && b < B){
                cout<<"L & R  "<<L+1<<" "<<R+1<<endl;
                cnt++; 
            }
            R++;
        }
        cout<<cnt<<endl;

    }
    return 0;
}

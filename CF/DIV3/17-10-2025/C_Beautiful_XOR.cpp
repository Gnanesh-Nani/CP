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
        int a,b;
        cin>>a>>b;
        if(a < b)
            cout<<-1<<endl;
        else if(a == b) 
            cout<<0<<endl;
        else {
            
            cout<<999<<endl;
        }
    }
    return 0;
}

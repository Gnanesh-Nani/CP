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
        int m,n;
        cin>>n>>m;
        for(int i =1; i <= n;i++){
            if(i <= m)
                cout<<"OK"<<endl;
            else    
                cout<<"Too Many Requests"<<endl;
        }
    }
    return 0;
}

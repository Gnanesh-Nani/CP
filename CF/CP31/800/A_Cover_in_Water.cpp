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
        int n;
        cin>>n;
        string str;
        cin>>str;

        int cost = -1;

        int i = 0;
        for(char c:str){
            if(c == '.'){
                i++;
                if(i == 3)
                    cost = 2;
            }
            else {
                i = 0;
            }
        }

        if(i == 3){
            cost = 2;
        }

        if(cost == -1 ){
            cost = 0;
            for(char c: str){
                cost += (c=='.');
            }
        }

        cout<<cost<<endl;
    }
    return 0;
}

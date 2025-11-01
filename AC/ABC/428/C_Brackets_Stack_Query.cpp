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
        int q;
        cin>>q;
        stack<char> S;
        int open = 0;
        int close = 0;
        int err = -1;
        for(int ii = 0;ii < q;ii++){
            int o;
            cin>>o;
            if(o == 1){
                char c;
                cin >> c;
                S.push(c);
                if(c == '('){
                    open++;
                } else {
                    close++;
                    if(close > open)
                    err = ii;
                }
            } else {
                char c = S.top();
                S.pop();
                if(c == '(')
                    open--;
                else {
                    close--;
                    if(S.size() == err){
                        err = -1;
                    }
                }
            }

            if(err != -1)
                cout<<"No"<<endl;
            else if (open != close)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
    }
    return 0;
}

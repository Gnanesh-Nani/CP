#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

int seive[1000006];
void compute_seive() {
    for(int i = 2; i <= 1000006;i++)
        seive[i] = 1;
    for(int i = 2; i*i <= 1000006;i++) {
        if(seive[i] == 1) {
            for(int j = 2*i; j <= 1000006;j = j + i) {
                seive[j] = 0;
            }
        }
    }
}

int f(int idx, int tight, int sum, string &str) {
    if(idx == str.length())
        return seive[sum];

    int ub = tight ? str[idx]-'0' : 9;

    int tot = 0;
    for(int i =0; i <= ub;i++){
        tot += f(idx + 1,tight && i == ub,sum + i,str);
    }
    return tot;
}

int32_t main()
{
    fastio;
    set_double_precision;
    compute_seive();

    int t = 1;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        string A = to_string(a-1);
        string B = to_string(b);
        //cout<<A<<" : "<<B<<endl;
        int uptoB = f(0,1,0,B);
        int uptoA = f(0,1,0,A);
        //cout<<uptoB<<" : "<<uptoA<<endl;
        cout<< (uptoB - uptoA) << endl;
    }
    return 0;
}


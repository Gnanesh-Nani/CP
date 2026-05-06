#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

// #define int long long
#define ll long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)


// seive upto 1e6
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


// 
string to_binary_str(ll num) {
    if(num == 0)
        return "0";
    string res = "";
    while (num > 0)
    {
        res += (num % 2 == 0)?'0':'1';
        num = num / 2;
    }
    reverse(res.begin(),res.end());
    return res;
}


ll dp[32][2][2][32][32];
ll f(int idx,int tight,int lz, int one, int zero, string &str) {
    if(dp[idx][tight][lz][one][zero] != -1)
        return dp[idx][tight][lz][one][zero];
    if(idx == str.length())
        return zero >= one;
    int ub = tight ? str[idx] - '0' : 1;

    ll tot = 0;
    for(int i = 0; i <= ub; i++) {
        int new_one = (i == 1) ? one + 1: one;
        int new_zero = (!lz && i == 0) ? zero + 1 : zero; 
        tot += f(idx + 1,tight && i == ub,lz && i==0,new_one,new_zero,str);
    }
    return dp[idx][tight][lz][one][zero] = tot;
}

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;

        string A = to_binary_str(a-1);
        string B = to_binary_str(b);

        // cout<<A<<" : "<<B<<endl;
        memset(dp,-1,sizeof(dp));
        ll uptoA = f(0,1,1,0,0,A);
        memset(dp,-1,sizeof(dp));
        ll uptoB = f(0,1,1,0,0,B);

         // cout<<uptoA<<" : "<<uptoB<<endl;
        ll ans = uptoB - uptoA;

        cout<<ans<<endl;
    }
    return 0;
}

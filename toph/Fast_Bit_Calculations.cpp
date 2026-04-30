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

// binary representation
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

// digit dp
ll dp[32][2][2][32];
ll f(int idx,int tight,int last, int cnt, string &str) {
    if(dp[idx][tight][last][cnt] != -1)
        return dp[idx][tight][last][cnt];
    if(idx == str.length())
        return cnt;

    int ub = tight ? str[idx] - '0' : 1;

    ll tot = 0;
    for(int i = 0; i <= ub; i++) {
        tot += f(idx + 1, tight && i == ub,i,cnt + (last == i && i==1), str);
    }
    return dp[idx][tight][last][cnt] = tot;
}

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        ll a;
        cin>>a;

        string A = to_binary_str(a);
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<tt<<": "<<f(0,1,0,0,A) <<endl;
    }
    return 0;
}

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



// 10 ^ 9
int mod = 1000000007;


ll dp[2001][2][2001];
// strart 
    // 0 -> start even
    // 1 -> start odd
    // 2 -> not started

ll f(int idx,int tight, int sum,int d,int m,string &str) {
    if(dp[idx][tight][sum] != -1)
        return dp[idx][tight][sum];
    if(idx == str.length())
        return sum == 0;
    int ub = tight ? str[idx] -'0' : 9;
    ll tot = 0;
    for(int i = 0; i <= ub; i++) {
        if(idx ==0 && i ==0)
            continue; // mf skipp lz
        int new_tight = tight && i==ub;
        int new_sum = (sum*10 + i)%m;
        if((idx%2 && i==d ) || (idx%2 == 0 && i!=d)) {
            int temp = f(idx+1,new_tight,new_sum,d,m,str);
            tot = (tot + temp)%mod;
        } 
    }
    return dp[idx][tight][sum] = tot;
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
        int m,d;
        cin>>m>>d;
        string A;
        string B;
        cin>>A;
        cin>>B;
        if(A != "0") {
            int n = A.length();
            int i = n-1;
            while(A[i] == '0') {
                A[i] = '9';
                i--;
            }
            A[i]--;
        }
        // cout<<A<<" : "<<B<<endl;
        memset(dp,-1,sizeof(dp));
        ll uptoA = f(0,1,0,d,m,A);
        // cout<<endl;
        memset(dp,-1,sizeof(dp));
        ll uptoB = f(0,1,0,d,m,B);

        ll ans = (mod + uptoB - uptoA)%mod;

        cout<<ans<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

int dp[20][10][2][2];

int f(int idx,int prev,int tight, int lz, string &s) {
    
    if(dp[idx][prev][tight][lz] != -1)
        return dp[idx][prev][tight][lz];

    if(idx == s.length())
        return 1;

    int lb = 0;
    int ub = tight ? (s[idx] - '0') : 9;

    int res = 0;
    for(int i =0; i <= ub;i++){

        if(!lz && prev == i)
            continue;
        
        res += f(idx + 1,i,(tight && i == ub),(lz && i==0),s);
    }

    return dp[idx][prev][tight][lz] = res;
};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {       
        int A;
        int B;
        cin>>A;
        cin>>B;

        string a = to_string(A-1);
        string b = to_string(B);

        memset(dp,-1,sizeof(dp));
        int x = f(0,10,1,1,b);

        memset(dp,-1,sizeof(dp));
        int y = f(0,10,1,1,a);

        cout<< (x-y) << endl;
    }
    return 0;
}

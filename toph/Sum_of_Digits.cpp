#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)


int dp[11][2][90];
int f(int idx,int tight,int sum,string &str){
    if(dp[idx][tight][sum] != -1)
        return dp[idx][tight][sum];
    if(idx == str.length())
        return sum;
    int ub = tight ? str[idx]-'0' : 9;

    int tot = 0;
    for(int i = 0; i <= ub;i++){
        tot += f(idx+1,tight && i == ub, sum + i, str);
    }
    return dp[idx][tight][sum] = tot;
}

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (1)
    {   
        int a;
        int b;
        cin>>a;
        cin>>b;
        
        if(a == -1 && b == -1)
            break;
        
        string A = to_string(a-1);
        string B = to_string(b);

        memset(dp,-1,sizeof(dp));
        int uptoA = f(0,1,0,A);

        memset(dp,-1,sizeof(dp));
        int uptoB = f(0,1,0,B);

        cout<< uptoB - uptoA <<endl;

    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION);


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

// idx
// tight
// last
int dp[11][2][11];
int f(int idx, int tight, int last,int mask, string &str) {
    if(dp[idx][tight][last] != -1)
        return dp[idx][tight][last];
    if(idx == str.length()) {
        return 1;
    }
    int ub = tight ? str[idx] - '0' : 9;
    
    int tot = 0;
    for(int i = 0;i <= ub;i++){
        if((mask & (1 << i)) && (last==10 || abs(last - i)<=2))
            tot += f(idx +1,tight && i == ub, i, mask, str);
    }
    return dp[idx][tight][last] = tot;
}

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t;tt++)
    {    
        int m,n;
        cin>>m>>n;
        int mask = 0;
        for(int i = 0; i < m;i++){
            int temp;
            cin>>temp;
            mask = mask | (1 << temp);
        }
        
        string A = "";
        string B = "9";
        
        for(int i = 0; i < n-1; i++) {
            A += "9";
            B += "9";
        }
        
        //cout<<A<<" : "<<B<<endl;
        
        int uptoA = 0; //f(0,1,10,mask,0,A);
        //cout<<endl;
        memset(dp,-1,sizeof(dp));
        int uptoB = f(0,1,10,mask,B);
        
        cout<<"Case "<<tt<<": "<<(uptoB - uptoA) <<endl;
    }
    return 0;
}

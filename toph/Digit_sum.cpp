#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

pair<int,int> f(int idx,int tight, string &str){
    if(idx == str.length())
        return {1,0}; // {cnt,sum}
    
    int ub = tight ? (str[idx] - '0') : 9;
    
    
    pair<int,int> res = {0,0};

    for(int i = 0; i <= ub;i++){
        pair<int,int> next = f(idx + 1,tight && i == ub, str);
        
        res.first += next.first;

        res.second += next.second + next.first * i;
    }

    return res;
}

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int a;
        int b;
        cin>>a>>b;

        string A = to_string(a == 0?a : a-1);
        string B = to_string(b);

        // cout<<A<<endl;
        // cout<<B<<endl;

        pair<int,int> uptoA = f(0,1,A);
        //cout<<uptoA.second<<endl;
        pair<int,int> uptoB = f(0,1,B);
        //cout<<uptoB.second<<endl;
        int ans = uptoB.second - uptoA.second;
        // sum of digits in the range is
        cout<<ans<<endl;

    }
    return 0;
}

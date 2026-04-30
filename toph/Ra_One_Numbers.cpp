#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

int f(int idx, int tight, int odd, int even ,string &str) {
    if(idx == str.length())
        return (even - odd )== 1;

    int ub = tight ? (str[idx] - '0') : 9;

    int tot = 0;
    for(int i = 0; i <= ub; i++){
        int new_odd = (idx%2 == 1)? odd + i : odd; 
        int new_even = (idx%2 == 0)? even + i : even;
        tot += f(idx+1,tight && i == ub, new_odd, new_even, str);
    }
    return tot;
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
        string A = to_string(a-1);
        string B = to_string(b);
        // cout<<A<<" "<<B<<endl;
        int uptoA = f(0,1,0,0,A);
        int uptoB = f(0,1,0,0,B);
        // cout<<uptoA << " : "<< uptoB <<endl;
        cout<< (uptoB - uptoA) <<endl;
    }
    return 0;
}

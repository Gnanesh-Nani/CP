#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

string convert(int r,int c){
    return to_string(r) + '#'+ to_string(c);
}

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int ans = 0;
        int n,m;
        cin>>n>>m;
        unordered_set<string> S;
        for(int i =0 ; i < m;i++){
            int r,c;
            cin>>r>>c;
            r--;
            c--;
            // cout<<i<<" : I"<<endl;
            if(S.count(convert(r,c)) == 0 && S.count(convert(r+1,c))==0 && S.count(convert(r,c+1))==0 && S.count(convert(r+1,c+1))==0) {
                ans++;
                S.insert(convert(r,c));
                S.insert(convert(r+1,c));
                S.insert(convert(r,c+1));
                S.insert(convert(r+1,c+1));
            }
        }
        // cout<<"Hi"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

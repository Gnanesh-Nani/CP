#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

void solve() {

};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    unordered_map<string,int> M;
    M["Ocelot"] = 0;
    M["Serval"] = 1;
    M["Lynx"] = 2;
    while (t--)
    {   
        string str1,str2;
        cin>>str1>>str2;
        if(M[str1] >
            = M[str2])
            cout<<"Yes"<<endl;
        else    
            cout<<"No"<<endl;
    }
    return 0;
}

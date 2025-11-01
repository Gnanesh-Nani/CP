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
    while (t--)
    {
        int n,k;
        string str;
        cin>>n>>k;
        cin>>str;
        map<string,int> F;

        int maxF = 0;
        for(int i = 0 ; i < n - k + 1 ; i++){
            string s(str.begin() + i,str.begin() + i + k);
            // cout<<"stubstr : "<<s<<endl;
            F[s]++;
            maxF = max(maxF,F[s]);
        }
        
        cout<<maxF<<endl;
        for(auto it : F){
            if(it.second == maxF)
                cout<<it.first<<" ";
        }
    }
    return 0;
}

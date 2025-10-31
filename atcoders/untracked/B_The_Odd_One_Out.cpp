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
    vector<int> M(26,0);
    string str;
    cin>>str;

    for(char c:str){
        M[c - 'a']++;
    }

    for(int i =0;i < 26;i++){
        if(M[i] == 1)
        {
            cout<< (char)(i + 'a')<<endl;
            return 0;
        }
    }

    return 0;
}

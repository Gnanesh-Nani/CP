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
        int n,m;
        cin>>n>>m;
        if(n == m){
            cout<<1<<endl;
            return 0;
        }
        vector<vector<char>> mat(n,vector<char>(n,0));
        for(int i =0 ;i < n;i++){
            for(int j =0; j < n;j++){
                cin>>mat[i][j];
            }
        }

        unordered_set<string> S;

        for(int i =0 ;i < n - m + 1;i++){
            for(int j =0; j < n - m + 1;j++){

                string str = "";
                for(int ii = i; ii < i + m;ii++){
                    for(int jj= j;jj < j + m;jj++){
                        str += mat[ii][jj];
                        str += "#";
                    }
                }
                S.insert(str);
            }
        }
        cout<<S.size()<<endl;
    }
    return 0;
}

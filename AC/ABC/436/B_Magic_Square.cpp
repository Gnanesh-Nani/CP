#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

void solve() {

};
int mod(int a,int b){
    return (a % b + b)%b;
};
int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> mat(n,vector<int>(n,-1));
        int r = 0;
        int c = (n-1)/2;
        mat[r][c] = 1;
        for(int i =0; i < n*n-1;i++){
            int r_ = mod(r-1,n);
            int c_ = mod(c+1,n);
            if(mat[r_][c_] == -1) {
                mat[r_][c_] = (mat[r][c] + 1);
            } else {
                r_ = mod(r+1,n);
                c_ = c;
                mat[r_][c_] = (mat[r][c] + 1);
            }
            r = r_;
            c = c_;
        }

        for(auto v: mat){
            for(int i: v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}

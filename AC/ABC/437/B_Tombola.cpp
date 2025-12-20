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
        int m,n,N;
        cin>>m>>n>>N;
        vector<unordered_set<int>> V(m);
        for(int i =0;i < m;i++){
            for(int j =0; j < n;j++){
                int temp; cin>>temp;
                V[i].insert(temp);
            }
        }

        vector<int> cntArr(m,0);
        for(int ii =0; ii < N;ii++){
            int temp;
            cin>>temp;
            for(int i=0;i < m;i++){
                if(V[i].count(temp))
                    cntArr[i]++;
            }
        }
        cout<< *max_element(cntArr.begin(),cntArr.end()) <<endl;
    }
    return 0;
}

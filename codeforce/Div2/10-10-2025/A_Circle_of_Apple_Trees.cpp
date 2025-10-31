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
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        unordered_set<int> S;

        for(int i =0; i < n;i++){
            int temp;
            cin>>temp;
            S.insert(temp);
        }

        cout<<S.size()<<endl;
    }
    return 0;
}

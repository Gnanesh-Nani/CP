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
        int n;
        cin>>n;
        unordered_map<int,int> Fmap;
        for(int i =0 ; i < n;i++){
            int temp;
            cin>>temp;
            Fmap[temp]++;
        }

        int cnt = 0;
        for(auto it:Fmap){
            int freq = it.second;
            if(freq >= 2){
                cnt += ((freq * (freq-1))/2)*(n - freq);
            }
        }

        cout<<cnt<<endl;
    }
    return 0;
}

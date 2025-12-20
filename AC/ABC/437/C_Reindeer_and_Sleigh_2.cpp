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
        vector<int> arr;
        int p_tot = 0;
        for(int i =0; i < n;i++){
            int w,p;
            cin>>w>>p;
            p_tot += p;
            arr.push_back(w + p);
        }
        sort(arr.begin(),arr.end());

        int i = 0;
        int sum = 0;
        while(i < n && p_tot - sum >= 0){
            sum += (arr[i]);
            i++;
        }
        cout<<i - 1<<endl;
    }
    return 0;
}

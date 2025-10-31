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
        vector<int> S1;
        vector<int> S2;

        int sum = (n * (n + 1))/2;

        if(sum %2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        
        if(n%2){
            int i = 1;
            int j = n-1;
            while(i < j){
                S1.push_back(i);
                S1.push_back(j);
                i++;
                j--;
                if(i < j){
                    S2.push_back(i);
                    S2.push_back(j); 
                    i++;
                    j--;
                }
            }
            S2.push_back(n);
        } else {

            int i = 1;
            int j = n;
            while(i < j){
                S1.push_back(i);
                S1.push_back(j);
                i++;
                j--;
                if(i < j){
                    S2.push_back(i);
                    S2.push_back(j); 
                    i++;
                    j--;
                }
            }
        }

        cout<<"YES"<<endl;
        cout<<S1.size()<<endl;
        for(int i:S1)
            cout<<i<<" ";
        cout<<endl;
        cout<<S2.size()<<endl;
        for(int i:S2)
            cout<<i<<" ";

    }
    return 0;
}

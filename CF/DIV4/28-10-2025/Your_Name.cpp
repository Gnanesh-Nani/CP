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
        string str1,str2;
        int n;
        cin>>n;
        cin>>str1>>str2;
        //cout<<str1<<endl<<str2<<endl;
        vector<int> map(26,0);
        for(char c: str1){
            map[c-'a']++;
        }
        for(char c: str2){
            map[c-'a']--;
        }
        bool flag = false;
        for(int i : map){
            if(i!=0){
                flag = true;
                break;;
            }
        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}

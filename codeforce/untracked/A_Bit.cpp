#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int t;
    string str;
    cin >> t;

    int ans = 0;

    for(int i =0; i < t;i++){
        cin >> str;
        if(str[1]=='+')
            ans++;
        else
            ans--;
    } 
    
    cout<<  ans;
    return 0;
}

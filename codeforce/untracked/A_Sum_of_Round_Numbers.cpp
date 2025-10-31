#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void f(int n){
    int d = 10;
    vector<int> ans;
    while(n > 0){
        int rem = n % d;
        if(rem != 0)
            ans.push_back(rem);
        n = (n/d)*d;
        d = d * 10;
    }

    cout<<ans.size()<<endl;
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fastio;
    int t,n;
    cin >> t;
    vector<int> nums;
    for(int i =0; i < t;i++){
        cin >> n;
        f(n);
    } 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int reverse(int x){
    int ans = 0;
    while(x > 0){
        int rem = x%10;
        ans = ans * 10 + rem;
        x = x /10;
    }
    return ans;
}

int32_t main() {
    fastio;

    int x,y;
    cin>>x>>y;

    for(int i = 2; i <= 10;i++){
        int n = x + y;
        x = y;
        y = reverse(n);
    }

    cout<<x;
    return 0;
}

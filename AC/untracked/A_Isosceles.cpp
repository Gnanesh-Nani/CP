#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;

    int a,b,c;
    cin>>a>>b>>c;
    if(a == b || b == c || a == c)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

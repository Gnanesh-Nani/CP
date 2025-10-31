#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;

    int at_a = abs(a-b) + abs(a-c);
    int at_b = abs(b-a) + abs(b-c);
    int at_c = abs(c-a) + abs(c-b);
    
    cout << min(at_a,min(at_b,at_c));
    
    return 0;
}

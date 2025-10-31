#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int x, c;
    cin>>x;
    cin>>c;
    
    
    int low = 0;
    int high = x;

    while(low <= high){
        int mid = (low + high)/2;

        int comm = (mid*c)/1000;
        if((comm + mid ) <= x){
            low = mid + 1;
        } else {
            high = mid -1;
        }

    }
    cout<<low;
    return  0;
}

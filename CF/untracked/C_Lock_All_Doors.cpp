#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i =0; i < n;i++)
        cin>>arr[i];

    int L = 0;
    int R = n-1;
    while(L < n && arr[L] != 0)
        L++;
    
    while(R >= 0 && arr[R] != 0)
        R--;
    
    int no_of_locked = 0;
    for(int i = L; i <= R;i++){
        if(arr[i] == 1)
            no_of_locked++;
    }

    cout<<(R - L  + no_of_locked);

    return 0;
}

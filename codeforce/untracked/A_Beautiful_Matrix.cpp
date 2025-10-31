#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int n = 5;
    vector<vector<int>> arr(5,vector<int>(5));
    int num;
    for(int i =0; i<n ;i++){
        for(int j =0; j<n;j++){
            cin >> num;
            arr[i][j] = num;
        }
    }

    for(int i  =0; i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                cout<<(abs(i-2) + abs(j-2));
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int f(int m,int n,vector<vector<int>> &arr){
    int cnt = 0;
    for(int i = m-2;i >= 0;i--){
        for(int j = n-2;j >= 0;j--){
            if(arr[i][j]==0 && arr[i+1][j]==0 && arr[i][j+1]==0 && arr[i+1][j+1] == 0)
            {
                cnt++;
                arr[i][j] = 1;
            }
        }
    }
    return cnt;
}
// # black
// . white
int32_t main() {
    fastio;
    int t;
    string str;
    cin >> t;
    vector<vector<int>> arr(9,vector<int>(9));
    while(t--){
        int h,w;// m , n
        cin>>h>>w;
        for(int i =0; i < h;i++){
            for(int j =0; j < w;j++){
                char c;
                cin>>c;
                if(c == '.')
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
                //cout<<arr[i][j]<<" ";
            }
            //cout<<endl;
        }

        cout<<f(h,w,arr)<<endl;
    }


    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

bool isPossible(int mindis,int k,int x,vector<int> &arr) {
    int n = arr.size();
    if(mindis == 0)
        return k <= x;
    int cnt = 0;
    for(int i = 0; i < n -1;i++){
        cnt += max(0LL,arr[i+1] - arr[i] - 1 - (mindis-1)*2);
    }
    cnt+= max(0LL,arr[0]-(mindis-1));
    cnt+= max(0LL,x - arr[n-1]-(mindis-1));
    return cnt >= k;
};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> arr;
        for(int i =0; i < n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = 1e9 + 1;
        int mid;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(mid,k,x,arr)){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout<<"Max-time : "<<high<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

int readInt(){
    int n;
    cin>>n;
    return n;
}

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int perimeter = 0;
        unordered_set<int> S;
        vector<int> arr;

        int maxL = INT_MIN;
        for(int i =0;i < n;i++){
            arr.push_back(readInt());
        }
        
        if(n < 2){
            cout<<0<<endl;
        }
        for(int i =0;i < n;i++){
            int temp = arr[i];
            if(S.count(temp))
            {   
                perimeter += 2*temp;
                S.erase(temp);
                maxL = max(temp,maxL);
            }else {
                S.insert(temp);
            }
        }

        if(perimeter == 0){
            cout<<0<<endl;
            continue;
        }

        int max1 = 0;
        int max2 = 0;

        for(int i: S){
            if(i > max1){
                max2 = max1;
                max1 = i;
            } else if(i > max2){
                max2 = i;
            }
        }
        maxL = max(maxL,max(max1,max2));
        int total = perimeter + max1 + max2;
        if(total-maxL <= maxL){
            cout<<0<<endl;
            continue;
        }
        cout<<total<<endl;
    }
    return 0;
}

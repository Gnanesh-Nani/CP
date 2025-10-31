#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)


int f(int A){
    int sum = 0;
    while(A > 0){
        sum += (A%10);
        A = A/10;
    }
    return sum;
}

int recur(int n) {
    if(n == 0)
        return 1;
    
    int A = recur(n-1);
    return  f(A) + A;
};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<recur(n-1)<<endl;
    }
    return 0;
}

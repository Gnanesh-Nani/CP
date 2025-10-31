#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 15

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

float dist(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int tsx,tsy,tgx,tgy;
        int asx,asy,agx,agy;
        cin>>tsx>>tsy>>tgx>>tgy;
        cin>>asx>>asy>>agx>>agy;

        float t_goal = dist(tsx,tsy,tgx,tgy);
        float a_goal = dist(asx,asy,agx,agy);

        float low = 0;
        float high = max(t_goal,a_goal);

        while(high-low > 10e-6){
            float mid = (low + high)/2;
            
            cout<<mid<<endl;
            break;
        }

    }
    return 0;
}

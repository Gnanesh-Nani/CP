#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

void solve() {

};

int32_t main()
{
    fastio;
    set_double_precision;

    int n,q;
    cin>>n>>q;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> PQ; 
    for(int i = 1;i <= n;i++){
        PQ.push({i,1});
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int cnt = 0;
        while(PQ.top()[0] <= a){
            cnt+= PQ.top()[1];
            PQ.pop();
        }
        PQ.push({b,cnt});
        cout<<cnt<<endl;
    }

    return 0;
}

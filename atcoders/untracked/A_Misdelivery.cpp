#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int n;
    cin>>n;
    unordered_map<int,string> Map;
    for(int i =1; i<= n;i++){
        string name;
        cin>>name;
        // cout<<i<<" : "<<name<<endl;
        Map[i] = name;
    }
    int x;
    string y;
    cin>>x>>y;
    // cout<<"x : "<<x<<endl;
    // cout<<"y : "<<y<<endl;
    if(Map[x] == y)
        cout<< "Yes";
    else
        cout<< "No";
}

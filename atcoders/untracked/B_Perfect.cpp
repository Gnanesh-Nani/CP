#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int n,m,k;
    cin>>n>>m>>k;
    unordered_map<int,int> M;
    for(int i =0; i < k; i++){
        int a,b;
        cin>>a>>b;
        M[a]++;
        if(M[a] == m)
            cout<< a << " ";
    }
    return 0;
}

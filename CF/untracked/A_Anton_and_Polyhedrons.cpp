#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int t;
    string polyhedrons;
    int cnt = 0;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>polyhedrons;
        if(polyhedrons[0] == 'T')
            cnt = cnt + 4;
        else if(polyhedrons[0] == 'C')
            cnt = cnt + 6;
        else if(polyhedrons[0] == 'O')
            cnt = cnt + 8;
        else if(polyhedrons[0] == 'D')
            cnt = cnt + 12;
        else if(polyhedrons[0] == 'I')
            cnt = cnt + 20;
    }
    cout<<cnt;
    return 0;
}

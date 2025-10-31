#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int32_t main()
{
    fastio;

    int n;
    cin >> n;
    
    vector<int> visited(n+1,0);
    vector<vector<int>> graph(n+1);
    queue<int> Q;

    int cnt = 0;
    for(int i = 1 ; i<= n;i++){
        int a,b;
        cin>>a>>b;
        if(a == 0 && b == 0)
        {
            Q.push(i);
        }
        
        if(a != 0)
            graph[a].push_back(i);
        if(b != 0)
            graph[b].push_back(i);
    }

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        if(visited[curr])
            continue;
        cnt++;
        visited[curr] = 1;
        for(int adj:graph[curr]){
            Q.push(adj);
        }
    }
    cout<<cnt;
    return 0;
}

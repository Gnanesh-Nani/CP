#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

int BLACK = 0;
int WHITE = 1;


int dfs(int curr,int parent,int curr_colour,vector<int> &color,vector<vector<int>> &graph,int n){
    // cout<< "dfs  "<<curr<< (curr_colour?"  WHITE":"  BLACK") <<endl;
    if(color[curr] != -1)
        return 0;

    int breaked_edge = 0;

    color[curr] = curr_colour;

    for(int i = 0;i < n;i++){
        if(graph[curr][i]==0 || i == parent)
            continue;
        if(color[i] == curr_colour){
            graph[curr][i] = 0;
            graph[i][curr] = 0;
            breaked_edge++;
        }
        breaked_edge += dfs(i,curr,!curr_colour,color,graph,n);
    }    

    return breaked_edge;
}


int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> graph(n,vector<int>(n,0));
        for(int i =0; i < m;i++){
            int u,v;
            cin>>u>>v;
            graph[u-1][v-1] = 1;
            graph[v-1][u-1] = 1;
        }
        vector<int> color(n,-1);
        cout<<dfs(0,-1,BLACK,color,graph,n);
    }
    return 0;
}

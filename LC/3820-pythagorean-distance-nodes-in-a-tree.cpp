#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int i, vector<int> &dist,vector<vector<int>> &adj) {
        queue<vector<int>> Q;
        Q.push({i,0});
        unordered_set<int> visited;

        while(!Q.empty()){
            auto curr = Q.front();Q.pop();
            int curr_node = curr[0];
            int curr_dis = curr[1];
            
            if(visited.count(curr_node)) 
                continue;

            visited.insert(curr_node);
            dist[curr_node] = curr_dis;

            for(int neigh: adj[curr_node]){
                if(visited.count(neigh))
                    continue;
                Q.push({neigh,curr_dis+1});
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> A(n,0); // bfs from x
        vector<int> B(n,0); // bfs from y
        vector<int> C(n,0); // bfs from z

        bfs(x,A,adj);
        bfs(y,B,adj);
        bfs(z,C,adj);

        int cnt = 0;
        
        for(int i = 0; i < n;i++){
            long long a = A[i];
            long long b = B[i];
            
            long long c = C[i];

            if(a*a + b*b == c*c)
                cnt++;
            else if(a*a + c*c == b*b )
                cnt++;
            else if(b*b + c*c == a*a)
                cnt++;
        }

        return cnt;
    }
};
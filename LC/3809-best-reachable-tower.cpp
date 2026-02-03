#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int cx = center[0];
        int cy = center[1];
        priority_queue<vector<int>> PQ;
        for(auto tower: towers){
            int x = tower[0];
            int y = tower[1];
            int q = tower[2];
            int dis = abs(x - cx) + abs(y - cy);
            if(dis <= radius)
                PQ.push({q,x,y});
        }
        if(PQ.empty())
            return  {-1,-1};
        vector<vector<int>> ans;
        int max_q = PQ.top()[0];
        while(!PQ.empty() && PQ.top()[0]==max_q) {
            auto tower = PQ.top();
            int x = tower[1];
            int y = tower[2];
            int q = tower[0];
            ans.push_back({x,y});
            PQ.pop();
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};
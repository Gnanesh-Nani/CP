#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bs(int end,vector<vector<int>> &intervals) {
        int l = 0;
        int h = intervals.size()-1;
        int ans = -1;
        while(l <= h){
            int mid = (l + h)/2;
            auto interval = intervals[mid];
            if(end <= interval[0]) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans==-1?-1: intervals[ans][2];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> inters;
        int n = intervals.size();
        vector<int> ans(n,-1);
        for(int i = 0; i < n;i++){
            auto sample = intervals[i];
            inters.push_back({sample[0],sample[1],i});
        }
        sort(inters.begin(),inters.end());
        
        for(int i = 0; i < n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int idx = bs(end,inters);
            ans[i] = idx;
        }

        return ans;
    }
};
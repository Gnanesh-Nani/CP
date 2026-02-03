#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int idx,int j,vector<int> &target,vector<int> &nums,vector<vector<int>> &memo) {
        if(memo[idx][j] != -1)
            return memo[idx][j];
        if(idx == nums.size()) {
            return 1;
        }
        int Xor = 0;
        int cnt = 0;
        for(int i = idx; i < nums.size();i++){
            Xor = Xor ^ nums[i];
            int new_j = (j == 0)?1: 0;
            if(Xor == target[j]) {
                cnt = (cnt + f(i+1,new_j,target,nums,memo))%(int)(1e9 + 7);
            }
        }
        return memo[idx][j] = cnt;
    }
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();
        vector<int> target = {target1,target2};
        vector<vector<int>> memo(n+1,vector<int>(2,-1));
        return f(0,0,target,nums,memo);
    }
};
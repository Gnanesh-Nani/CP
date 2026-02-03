#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> S;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            if(nums[i] != target[i]) {
                if(S.count(nums[i]) == 0) {
                    S.insert(nums[i]);
                }
            }
        }
        return S.size();
    }
};
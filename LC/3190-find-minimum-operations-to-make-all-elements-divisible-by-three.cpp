#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cost = 0;
        for(int i: nums){
            int extra = i%3;
            cost += min(extra,3-extra);
        }
        return cost;
    }
};
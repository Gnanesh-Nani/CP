#include <bits/stdc++.h>
#include <vector>
int noOfOperation(long long penalty,long long k,const vector<long long>& nums){
    int n = nums.size();
    int op = 0;
    for(int i = n - k - 1 ; i >= 0;i--){
        if(nums[i] > penalty){
            op += nums[i]/penalty + (nums[i]%penalty != 0);
        } else {
            break;
        }
    }
    return op;
}
long long minimizeKth(const std::vector<long long>& nums, long long maxOperations, long long K) {
    int low = 0;
    int high = accumulate(nums.begin(),nums.end(),0);
    int ans = INT_MAX;
    sort(nums.begin(),nums.end());
    while(low <= high){
        long long mid = low + (high-low)/2;
        if(noOfOperation(mid,K,nums) <= maxOperations){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

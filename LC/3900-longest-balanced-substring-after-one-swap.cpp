#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    // there are 3 cases
    // if there exist a sum where idx
    int longestBalanced(string s) {
        int tot_0 = 0;
        int tot_1 = 0;

        for(char c: s){
            if(c == '0')
                tot_0++;
            else
                tot_1++;
        }
        
        int ans = 0;
        int prefix = 0;
        int n = s.length();
        unordered_map<int,int> M; // stores the first occurence of prefix M   
        unordered_map<int,int> M1; // stores the first occurece of prefix M after seeing alteat one 1
        unordered_map<int,int> M0; // stores the first occurence of prefix M after seeing atlest one 0
        bool seen1 = false;
        bool seen0 = false;
        M[0] = -1; 
        for(int i = 0; i < n; i++) {
            prefix += (s[i]=='1')?1:-1;

            // case 1
            // a sub array of sum 0
            if(s[i] == '1')
                seen1 = true;
            if(s[i] == '0')
                seen0 = true;

            if(M.count(prefix))
                ans = max(ans,i - M[prefix]);
            
            // a sub array of sum +2 - one extra 1
            if(M.count(prefix - 2)) {
                int idx = M[prefix - 2]; // try left most prefix sum
                int n0 = (i - idx) / 2 - 1;
                if(tot_0 > n0)
                    ans = max(ans, i - idx); // handles the case of 0 on right side
                else {
                    // explicilty try after seeing one 0
                    if(M0.count(prefix - 2)) {
                        int idx2 = M0[prefix - 2];
                        ans = max(ans, i - idx2);    
                    }
                }
            } 

            // a sub array of sum -2 - one extra 0
            if(M.count(prefix + 2)) {
                int idx = M[prefix + 2];
                int n1 =  (i-idx)/2 - 1;
                if(tot_1 > n1)
                    ans = max(ans, i - idx);
                else {
                    if(M1.count(prefix + 2)) {
                        int idx2 = M1[prefix + 2];
                        ans = max(ans,i-idx2);
                    }
                }
            }

            if(M.count(prefix) == 0)
                M[prefix] = i;
            if(M1.count(prefix) == 0 && seen1)
                M1[prefix] = i;
            if(M0.count(prefix) == 0 && seen0)
                M0[prefix] = i;
        }

        return ans;
    }
};
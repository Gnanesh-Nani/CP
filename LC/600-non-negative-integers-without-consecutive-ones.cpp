#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string to_binary_string(int n) {
        string ans = "";
        while( n > 0){
            ans += (n % 2) ? "1":"0";
            n = n/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int f(int idx,int tight,int prev,int repeat,string str) {
        if(idx == str.length()){
            return repeat;
        }
        int ub = tight ? str[idx] - '0' : 1;  

        int cnt = 0;
        for(int i = 0; i <= ub; i++){
            cnt += f(idx+1,(tight && i == ub),i,repeat || (i==1 && prev == 1), str);
        }
        return cnt;
    }

    int findIntegers(int n) {
        string str = to_binary_string(n);
        cout<<str<<endl;
        return f(0,1,0,0,str);
    }

};
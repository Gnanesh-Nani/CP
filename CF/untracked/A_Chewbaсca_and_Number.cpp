#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int32_t main()
{
    fastio;
    string number;
    cin >> number;

    int n = number.length();

    bool has_non_zero = false;
    
    for(int i = 0 ;i < n;i++){
        if(number[i] >= '5'){
            if(i==0 && number[i] == '9')
                continue;           
            else
                number[i] =  '0' + ('9' - number[i]);
        }   
    }
    cout<<number;
    return 0;
}

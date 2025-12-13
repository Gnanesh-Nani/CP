#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        int zero = 0, one = 0;
        for (char c : str) (c == '0' ? zero++ : one++);
        int n_zero = 0;
        int n_one = 0;
        for(int i = 0; i < k;i++){
            int flag = true;
            for(int j = i; j < n;j+=k){
                if(flag){
                    flag = false;
                    n_zero++;
                } else {
                    flag = true;
                    n_one++;
                }
            }
        }
        
        // cout<<n_one<<" : "<<n_zero<<endl;
        if(((one == n_one) && (zero == n_zero)) || ((zero == n_one) && (one == n_zero)))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
}

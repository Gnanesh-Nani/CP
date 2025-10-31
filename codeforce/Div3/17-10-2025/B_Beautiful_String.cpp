#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)


bool isPalindrome(string str){
    int i = 0;
    int n = str.length();
    for(int i =0; i < n/2;i++)
    {
        if(str[i] != str[n-i-1])
            return false;
    }
    return true;
}

bool f(int i,char last,vector<int> &subseq,string &rem,string &str) {
    if(i == str.size()){
        if(isPalindrome(rem))
        {
            cout<<subseq.size()<<endl;
            for(int i:subseq)
                cout<<i<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    subseq.push_back(i+1);
    if(!(last=='1' && str[i]=='0') && f(i+1,str[i],subseq,rem,str))
        return true;
    subseq.pop_back();

    rem.push_back(str[i]);
    if(f(i+1,last,subseq,rem,str))
        return true;
    rem.pop_back();

    return false;
};

int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,temp;
        cin>>n;
        string str;
        cin>>str;

        vector<int> subseq;
        string rem;
        f(0,'0',subseq,rem,str);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
#define all(x) (x).begin(), (x).end()


#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

int aleast_nA_atmost_mB(int i,int n_a,int m_b,vector<int> &prefixA, vector<int> &prefixB){
    int low = 0;
    int high = i;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int no_of_a_btw = (mid == 0) ? prefixA[high]:prefixA[high] - prefixA[mid-1]; 
        int no_of_b_btw = (mid == 0) ? prefixB[high]:prefixB[high] - prefixB[mid-1];
        if(no_of_a_btw < n_a)
            high = mid - 1;
        else {
            if(no_of_b_btw >= m_b)
                low = mid + 1;
            else {
                high = mid - 1;
                ans = mid;
            }
        }
    }
    return ans;
}



int32_t main()
{
    fastio;
    set_double_precision;

    int t = 1;
    // cin >> t;
    // fix it
    while (t--)
    {
        int n,A,B;
        cin>>n>>A>>B;
        string str;
        cin>>str;

        int cnt = 0;
        vector<int> prefixA(n,0);
        vector<int> prefixB(n,0);
        vector<int> lastB(n,-1);
        prefixA[0] = (str[0] == 'a');
        prefixB[0] = (str[0] == 'b'); 
        int last_seen_b = -1;
        for(int i =0;i < n;i++){
            cout<<"i : "<<i<<endl;
            lastB[i] = last_seen_b;
            if(i > 0){
                prefixA[i] = prefixA[i-1] + (str[i]=='a');
                prefixB[i] = prefixB[i-1] + (str[i]=='b');
            }
            int j = aleast_nA_atmost_mB(i,A,B,prefixA,prefixB);
            int k = -1;
            if(j != -1)
                k = lastB[j];
            cout<<"j and k : "<<j<<"  "<<k<<endl;
            cnt += (k - j + 1);

            if(str[i] == 'b')
                last_seen_b = i;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

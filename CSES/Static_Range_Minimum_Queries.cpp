#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

// #define int long long
#define ll long long
#define all(x) (x).begin(), (x).end()

#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)

// seive upto 1e6
int seive[1000006];
void compute_seive() {
    for(int i = 2; i <= 1000006;i++)
        seive[i] = 1;
    for(int i = 2; i*i <= 1000006;i++) {
        if(seive[i] == 1) {
            for(int j = 2*i; j <= 1000006;j = j + i) {
                seive[j] = 0;
            }
        }
    }
}

// binary representation
string to_binary_str(ll num) {
    if(num == 0)
        return "0";
    string res = "";
    while (num > 0)
    {
        res += (num % 2 == 0)?'0':'1';
        num = num / 2;
    }
    reverse(res.begin(),res.end());
    return res;
}

// =========================== Segment Tree ============================= 


vector<int> seg;
void build(int idx, int low,int high, vector<int> &arr) {
    // cout<<"b : "<<idx<<" "<<low<<" "<<high<<endl;
    if(low == high) {
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high)/2;
    int left = idx*2 + 1;
    int right = idx*2 + 2;

    build(left, low,mid,arr);
    build(right, mid + 1,high, arr);

    seg[idx] = min(seg[left],seg[right]);
}

void buildSeg(int n,vector<int> &arr) {
    seg.resize(4*n,0);
    build(0,0,n-1,arr);
    // cout<<"Succesfully Build Segment Tree"<<endl;
}

int query(int idx, int low,int high, int l,int r) {
    //cout<<"q : "<<idx<<" "<<low<<" "<<high<<endl;

    if(l <= low && high <= r)
        return seg[idx];
    if(high < l || r < low)
        return INT_MAX;

    int mid = (low + high)/2;
    int left = idx*2 + 1;
    int right = idx*2 + 2;

    return min(query(left,low,mid,l,r),query(right,mid+1,high,l,r));
}

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i =0; i < n; i++)
            cin>>arr[i];
        buildSeg(n,arr);
        for(int i = 0; i < q; i++) {
            int l,r;
            cin>>l>>r; // 1 based indexing query so reduce 1

            cout<<query(0,0,n-1,l-1,r-1) << endl;
        }
    }
    return 0;
}

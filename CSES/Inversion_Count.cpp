#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

// #define int long long
#define ll long long
#define all(x) (x).begin(), (x).end()

#define fastio  ios::sync_with_stdio(false);cin.tie(nullptr);
#define set_double_precision cout<<fixed<<setprecision(DOUBLE_PRECISION)


// ====================== Decimal to Binary ===========================
// 10 -> "1010"
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


// ======================== Seive upto 1e6 =============================
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

// =========================== Segment Tree =============================
// default range sum
class SGTree {
  int n;
  vector < int > seg;
  public:
    SGTree(int n, vector < int > & arr) {
      seg.resize(4 * n, 0);
      this -> n = n;
      build(0, 0, n - 1, arr);
    }

  void build(int idx, int low, int high, vector < int > & arr) {
    if (low == high) {
      seg[idx] = arr[low];
      return;
    }

    int mid = (low + high) / 2;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    build(left, low, mid, arr);
    build(right, mid + 1, high, arr);

    seg[idx] = seg[left] + seg[right];
  }

  int query(int idx, int low, int high, int l, int r) {

    if (l <= low && high <= r)
      return seg[idx];
    if (high < l || r < low)
      return 0;

    int mid = (low + high) / 2;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    return query(left, low, mid, l, r) + query(right, mid + 1, high, l, r);
  }

  // point update
  void update(int idx, int low, int high, int i) {
    if (low == high) {
      seg[idx]++;
      return;
    }

    int mid = (low + high) / 2;

    if (i <= mid)
      update(idx * 2 + 1, low, mid, i);
    else
      update(idx * 2 + 2, mid + 1, high, i);

    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
  }
};


int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin>>nums[i];
        }

        int maxi = *max_element(nums.begin(),nums.end());


        vector<int> freq(maxi+1,0);
        // for(int i: nums)
        //     freq[i]++;
        SGTree S(maxi+1,freq);

        ll cnt  = 0;
        for(int i = 0; i < n; i++) {
            // query from num[i]+1 to maxi
            if(nums[i] != maxi)
                cnt += S.query(0,0,maxi,nums[i]+1,maxi);
            S.update(0,0,maxi,nums[i]);
        }

        cout<<cnt<<endl;
    }
    return 0;
}

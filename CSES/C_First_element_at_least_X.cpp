#include <bits/stdc++.h>
using namespace std;

#define DOUBLE_PRECISION 20

#define int long long
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

    seg[idx] = max(seg[left] , seg[right]);
  }

  int query(int idx, int low, int high, int val) {
    if(seg[idx] < val)
      return -1;
    if(low == high)
      return low;

    int mid = (low + high) >> 1; 
    if(seg[2*idx + 1] >= val)
      return query(2*idx+1, low, mid, val);
    else
      return query(2*idx+2, mid + 1, high, val);
  }

  // point update
  void update(int idx, int low, int high, int i, int val) {
    if (low == high) {
        seg[idx] = val;
        return;
    }

    int mid = (low + high) / 2;

    if (i <= mid)
      update(idx * 2 + 1, low, mid, i, val);
    else
      update(idx * 2 + 2, mid + 1, high, i, val);

    seg[idx] = max(seg[idx * 2 + 1] , seg[idx * 2 + 2]);
  }
};


int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    //  cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int q;
        cin >>q;
        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        SGTree S(n,arr);
        
        for(int i = 0; i < q; i++ ) {
          int type;
          cin >> type;
          if(type == 1) {
            int idx,val;
            cin >> idx >> val;
            S.update(0,0,n-1,idx,val);
          } else {
            int val;
            cin >> val;
            cout << S.query(0,0,n-1,val) <<  endl;
          }
        }
    }
    return 0;
}

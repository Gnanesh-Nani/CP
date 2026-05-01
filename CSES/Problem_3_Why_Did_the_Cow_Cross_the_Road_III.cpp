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
  public:
  int n;
  vector < int > seg;
    SGTree(int n, vector < int > & arr) {
      seg.resize(4 * n, 0);
      this -> n = n;
      // build(0, 0, n - 1, arr);
    }

//   void build(int idx, int low, int high, vector < int > & arr) {
//     if (low == high) {
//       seg[idx] = 1;
//       return;
//     }

//     int mid = (low + high) / 2;
//     int left = idx * 2 + 1;
//     int right = idx * 2 + 2;

//     build(left, low, mid, arr);
//     build(right, mid + 1, high, arr);

//     seg[idx] = seg[left] + seg[right];
//   }

  void update(int idx,int low,int high, int i, int delta) {
    if(low == high) {
        seg[idx] += delta;
        return;
    }
    int mid = (low + high)/2;
    if(i <= mid) 
        update(2*idx+1,low,mid,i,delta);
    else
        update(2*idx+2,mid+1,high,i,delta);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
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

};


int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    int t = 1;
    //  cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> arr(2*n,0);
        SGTree ST(2*n, arr);

        unordered_map<int,int> M;

        ll cnt  = 0;

        for(int i = 0; i < 2*n; i++) {
            int val;
            cin >> val;
            
            if(M.count(val) == 0) {
                M[val] = i;
                ST.update(0,0,2*n-1,i,1);
                // for(int i: ST.seg)
                //     cout << i << " ";
                // cout << endl;
                
            } else {
                cnt += ST.query(0,0,2*n-1,M[val] + 1,i);
                ST.update(0,0,2*n-1,M[val],-1);
            }
            
        }

        cout << cnt << endl;

    }
    return 0;
}

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
  void update(int idx, int low, int high, int i,int val) {
    if (low == high) {
      seg[idx] = val;
      return;
    }

    int mid = (low + high) / 2;

    if (i <= mid)
      update(idx * 2 + 1, low, mid, i, val);
    else
      update(idx * 2 + 2, mid + 1, high, i, val);

    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
  }
};

class EulerTour {
    public:
    int tim = 1;
    vector<int> inTime;
    vector<int> outTime;
    vector<int> eulerArr;

    EulerTour(int n) {
        inTime.resize(n+1,0);
        outTime.resize(n+1,0);
        eulerArr.push_back(-1);
    }

    void tour(int node,int par, vector<vector<int>> &adj,vector<int> &values) {
        inTime[node] = tim;
        tim++;
        eulerArr.push_back(values[node]);
        for(int i: adj[node]) {
            if(i == par)
                continue;
            tour(i,node,adj,values);
        }
        eulerArr.push_back(values[node]);
        outTime[node] = tim;
        tim++;
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
        int n,q;
        cin >> n >> q;

        vector<vector<int>> adj(n+1);
        vector<int> values(n+1);

        for(int i = 1; i <= n; i++) {
            cin >> values[i];
        }

        for(int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            // cout << u << " : "  << v << endl;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        EulerTour ET(n);
        ET.tour(1,0,adj,values);
        
        int e = ET.eulerArr.size();

        SGTree ST(e,ET.eulerArr);

        for(int i =0; i < q; i++) {
            int type;
            cin >> type;

            if(type == 1) {
                int x,val;
                cin >> x >> val;
                int inT = ET.inTime[x];
                int outT = ET.outTime[x];
                ST.update(0,0,e-1,inT,val);
                ST.update(0,0,e-1,outT,val);
            } else {
                int x;
                cin >> x;
                int inT = ET.inTime[x];
                int outT = ET.outTime[x];
                cout << (ST.query(0,0,e-1,inT,outT)/2) << endl;
            }
        }

    }
    return 0;
}

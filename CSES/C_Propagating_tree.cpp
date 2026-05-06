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

// SG Tree Lazy propagation
class SGTree {
    int n;
    vector<int> seg, lazy;

public:
    SGTree(int n, vector<int> &arr) {
        this->n = n;
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    // Build
    void build(int idx, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Push lazy updates
    void push(int idx, int low, int high) {
        if (lazy[idx] != 0) {
            seg[idx] += (high - low + 1) * lazy[idx];

            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }
    }

    // Range Update: add val to [l, r]
    void rangeUpdate(int idx, int low, int high, int l, int r, int val) {
        push(idx, low, high);

        // No overlap
        if (high < l || r < low) return;

        // Complete overlap
        if (l <= low && high <= r) {
            lazy[idx] += val;
            push(idx, low, high);
            return;
        }

        int mid = (low + high) / 2;

        rangeUpdate(2 * idx + 1, low, mid, l, r, val);
        rangeUpdate(2 * idx + 2, mid + 1, high, l, r, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Range Query
    int query(int idx, int low, int high, int l, int r) {
        push(idx, low, high);

        // No overlap
        if (high < l || r < low) return 0;

        // Complete overlap
        if (l <= low && high <= r) return seg[idx];

        int mid = (low + high) / 2;

        return query(2 * idx + 1, low, mid, l, r) +
               query(2 * idx + 2, mid + 1, high, l, r);
    }

    // Point Update: increment index i by 1
    void pointUpdate(int idx, int low, int high, int i) {
        push(idx, low, high);

        if (low == high) {
            seg[idx] += 1;
            return;
        }

        int mid = (low + high) / 2;

        if (i <= mid)
            pointUpdate(2 * idx + 1, low, mid, i);
        else
            pointUpdate(2 * idx + 2, mid + 1, high, i);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};

// Generate Euler tour
int tim = 1;
vector<int> eulerTour = {-1};
vector<int> inTime(2e5+1);
vector<int> outTime(2e5+1);
vector<int> height(2e5+1);
vector<int> value(2e5+1);

void tour(int node,int parent,int h, vector<vector<int>> &adj) {
  height[node] = h;
  int val = (h & 1)? value[node] : -1 * value[node];
  eulerTour.push_back(val);
  inTime[node] = tim;
  tim++;
  for(int i: adj[node]) {
    if(i == parent)
      continue;
    tour(i,node,h+1,adj);
  }
  eulerTour.push_back(val);
  outTime[node] = tim;
  tim++;
}

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    //  cin >> t;
    while (t--)
    {
      int n,m;
      cin >> n >> m;

      for(int i = 1; i <= n; i++) {
        cin >> value[i];
      }

      vector<vector<int>> adj(n+1);
      for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        // cout << u << " : " << v << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      tour(1,-1,1,adj);

      // for(int i: eulerTour)
      //   cout << i << " ";
      // cout << endl;
      
      int e = eulerTour.size();
      SGTree ST(e,eulerTour);

      for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if(type == 1) {
          int x,val;
          cin >> x >> val;
          if(height[x] % 2) {
            ST.rangeUpdate(0,0,e-1,inTime[x],outTime[x],val);
          } else {
            ST.rangeUpdate(0,0,e-1,inTime[x],outTime[x],-1*val);
          }

        } else {
          int ans;
          int x;
          cin >> x;
          if(height[x] % 2) {
            ans = ST.query(0,0,e-1,inTime[x],inTime[x]);
          } else {
            ans = -1 * ST.query(0,0,e-1,inTime[x],inTime[x]);
          }
          cout << ans << endl;
        }
      }

    }
    return 0;
}

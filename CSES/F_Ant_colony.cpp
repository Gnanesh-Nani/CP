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

// ============================= Node Segment Tree =============================
class Node {
    public:
    int cnt;
    int min;
    int gcd_r;
    Node(int c,int m,int g) {
        cnt = c;
        min = m;
        gcd_r = g;
    }
};
class NodeSegTree {
    public:
    int n;
    vector<Node> seg;
    NodeSegTree(int n,vector<int> &arr) {
        seg.resize(4*n,Node(0,0,0));
        this->n = n;
        build(0,0,n-1,arr);
    }
    Node construct(Node A, Node B) {
        if(A.gcd_r == 0)
            return B;
        if(B.gcd_r == 0)
            return A;
        int c=0,m,g;
        m = min(A.min,B.min);
        if(m == A.min)
            c+= A.cnt;
        if(m == B.min)
            c+= B.cnt;
        g = gcd(A.gcd_r,B.gcd_r);
        return Node(c,m,g);
    }
    void build(int idx, int low, int high, vector<int> &arr) {
        if(low == high) {
            seg[idx] = Node(1,arr[low],arr[low]);
            return;
        }
        int mid = (low + high) /2;
        build(idx*2+1,low,mid,arr);
        build(idx*2+2,mid+1,high,arr);      
        seg[idx] = construct(seg[idx*2+1],seg[idx*2+2]);
    }   
    Node query(int idx, int low,int high,int l,int r) {
        // complete over lap low l r high
        if (l <= low && high <= r){
            return seg[idx];
        }

        // low high l r  ---- or --- l r low high
        // no overlap
        if(high < l  || r < low) {
            return Node(0,0,0);
        }

        // partial overlap
        int mid =  (low + high)/2;
        Node left = query(idx*2+1,low,mid,l,r);
        Node right = query(idx*2+2,mid+1,high,l,r);

        return construct(left,right);
    }
};

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin>>n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin>>nums[i];
        }

        NodeSegTree S(n,nums);

        // int i = 0;
        // for(Node n: S.seg) {
        //      // cout<<i << " -> " << n.cnt << " " << n.min << " " << n.gcd_r << endl;
        //     i++;
        // }
            
        int q;
        cin>>q;
        while(q--) {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            Node ans = S.query(0,0,n-1,l,r);
            // cout<<l << " " << r << " q> " << ans.cnt << " " << ans.min << " " << ans.gcd_r << endl;
            if(ans.gcd_r == ans.min)
                cout << (r-l + 1 -ans.cnt) << endl;
            else
                cout << (r-l+1) << endl;
        }
    }
    return 0;
}

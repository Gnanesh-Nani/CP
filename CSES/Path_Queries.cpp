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
    vector<long long> seg, lazy;

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
};

class EulerTour {
    public:
    int tim = 1;
    vector<int> eulerTour;
    vector<int> inTime;
    vector<int> outTime;
    vector<long long> depth;
    vector<int> parent;

    EulerTour(int n, vector<vector<int>> &adj,vector<int> &values) {
        inTime.resize(n+1,0);
        outTime.resize(n+1,0);
        depth.resize(n+1,0);
        parent.resize(n+1,0);
        eulerTour.push_back(-1);
        depth[1] = values[1];
        tour(1,0,adj,values);
    }

    void tour(int node,int par, vector<vector<int>> &adj,vector<int> &values) {
        inTime[node] = tim;
        tim++;
        eulerTour.push_back(values[node]);

        parent[node] = par;
        for(int i: adj[node]) {
            if(i == par)
                continue;
            depth[i] = depth[node] + values[i];
            tour(i,node,adj,values);
        }

        eulerTour.push_back(values[node]);
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

        vector<int> values(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> values[i];
        }
        vector<vector<int>> adj(n+1);

        for(int i = 0; i < n-1;i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        EulerTour ET(n,adj,values);
        // ET.tour(1,0,adj,values);

        vector<long long> oldDepth = ET.depth;

        // for(int i: ET.eulerTour)
        //     cout << i << " ";
        // cout << endl;

        // for(int i: ET.inTime)
        //     cout << i << " ";
        // cout << endl;

        // for(int i: ET.outTime)
        //     cout << i << " ";
        // cout << endl;
        
        // for(int i: ET.depth)
        //     cout << i << " ";
        // cout << endl << endl;

        int e = ET.eulerTour.size();
        vector<int> arr(e,0);
        SGTree S(e,arr);

        for(int i = 0; i < q; i++) {
            int type;
            cin >> type;
            if(type == 1){ 
                int x,val;
                cin >> x >> val;
                
                int diff = val - values[x];
                // cout << "diff : " << diff << endl;
                // cout << "old Depth : " << values[x] << endl;
                
                values[x] = val;
                S.rangeUpdate(0,0,e-1,ET.inTime[x],ET.outTime[x],diff);
                
            } else {
                int x;
                cin >> x;
                int temp = S.query(0,0,e-1,ET.inTime[x],ET.inTime[x]);
                // cout << "depth : " << ET.depth[x] << endl;
                // cout << "temp : " << temp << endl; 
                cout << ET.depth[x] + temp << endl;
            }   
            // cout << endl << endl;
        }
    }   
    return 0;
}

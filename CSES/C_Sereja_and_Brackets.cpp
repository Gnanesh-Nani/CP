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


// class SGTree {
//   int n;
//   vector<Node*> seg;
//   public:
//     SGTree(int n, vector < int > & arr) {
//       seg.resize(4 * n);
//       this -> n = n;
//       build(0, 0, n - 1, arr);
//     }

//   void build(int idx, int low, int high, vector < int > & arr) {
//     if (low == high) {
//       Node* temp = new Node(arr[low],0,0)
//       seg[idx] = arr[low];
//       return;
//     }

//     int mid = (low + high) / 2;
//     int left = idx * 2 + 1;
//     int right = idx * 2 + 2;

//     build(left, low, mid, arr);
//     build(right, mid + 1, high, arr);

//     seg[idx] = seg[left] + seg[right];
//   }

//   int query(int idx, int low, int high, int l, int r) {

//     if (l <= low && high <= r)
//       return seg[idx];
//     if (high < l || r < low)
//       return 0;

//     int mid = (low + high) / 2;
//     int left = idx * 2 + 1;
//     int right = idx * 2 + 2;

//     return query(left, low, mid, l, r) + query(right, mid + 1, high, l, r);
//   }

//   // point update
//   void update(int idx, int low, int high, int i, int val) {
//     if (low == high) {
//       seg[idx] = val;
//       return;
//     }

//     int mid = (low + high) / 2;

//     if (i <= mid)
//       update(idx * 2 + 1, low, mid, i, val);
//     else
//       update(idx * 2 + 2, mid + 1, high, i, val);

//     seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
//   }
// };

class Node {
    public:
    int open;
    int close;
    int full;

    Node(int o,int c, int f) {
        this->open = o;
        this->close = c;
        this->full = f;
    }
};


class SGTree {
    public:
    string str;
    int n;
    vector<Node*> seg;
    SGTree(int n, string str) {
        seg.resize(4*n,nullptr);
        this->str = str;
        this->n = n;
        build(0,0,n-1);
    }

    Node* merge(Node* A, Node* B){
        int match = min(A->open,B->close);
        int o = A->open + B->open - match;
        int c = A->close + B->close - match; 
        int f = A->full + B->full + match;
        return new Node(o,c,f);
    }

    void build(int idx, int low,int high) {
        if(low == high) {
            char ch = str[low];
            int o = (ch=='(')?1:0;
            int c = (ch==')')?1:0;
            seg[idx] = new Node(o,c,0);
            return;
        }

        int mid = (low + high)/2;

        build(idx*2+1,low,mid);
        build(idx*2+2,mid+1,high);

        seg[idx] = merge(seg[idx*2+1],seg[idx*2+2]);
    }

    Node* query(int idx, int low,int high, int l,int r) {
        // full overlap
        // l low high r
        if(l <= low && high <= r) {
            return seg[idx];
        }

        // no overlap
        // low high l r   -----   or   ----  l r low high
        if(high < l || r < low) {
            return new Node(0,0,0);
        }

        // partial overlap
        int mid = (low + high)/2;
        Node *left = query(idx*2+1,low,mid,l,r);
        Node *right = query(idx*2+2,mid+1,high,l,r);
        return merge(left,right);
    }
};

int32_t main()
{
    fastio;
    set_double_precision;
    // compute_seive();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        string str;
        cin>>str;
        int n = str.length();

        int m;
        cin>>m;

        SGTree T(n,str);

        // for(int i = 0; i < T.seg.size(); i++){
        //     if(T.seg[i] == nullptr)
        //         continue;
        //     cout<<i<<" ";
        //     cout<<T.seg[i]->open<<" ";
        //     cout<<T.seg[i]->close<<" ";
        //     cout<<T.seg[i]->full<<" ";
        //     cout<<endl;
        // }

        for(int i = 0; i < m; i++) {
            int l,r;
            cin>>l>>r;
            l--;r--;

            Node* ans = T.query(0,0,n-1,l,r);

            cout << (ans->full*2) << endl;
        }
    }
    return 0;
}

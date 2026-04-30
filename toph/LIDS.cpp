#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Node {
    int len;
    ll ways;
    Node(int l = 0, ll w = 0) : len(l), ways(w) {}
};

string L, R;

// dp[pos][last+1][mask][started][tightL][tightR]
Node dp[11][11][1 << 10][2][2][2];
bool vis[11][11][1 << 10][2][2][2];

Node mergeNode(Node a, Node b) {
    if (a.len > b.len) return a;
    if (b.len > a.len) return b;
    return Node(a.len, a.ways + b.ways);
}

Node f(int pos, int last, int mask, int started, int tightL, int tightR) {
    if (pos == (int)R.size()) {
        if (!started) return Node(0, 1);
        return Node(__builtin_popcount(mask), 1);
    }

    if (vis[pos][last + 1][mask][started][tightL][tightR])
        return dp[pos][last + 1][mask][started][tightL][tightR];

    int lo = tightL ? L[pos] - '0' : 0;
    int hi = tightR ? R[pos] - '0' : 9;

    Node res(0, 0);

    for (int d = lo; d <= hi; d++) {
        int ntightL = tightL && (d == lo);
        int ntightR = tightR && (d == hi);

        if (!started && d == 0) {
            Node temp = f(pos + 1, last, mask, 0, ntightL, ntightR);
            res = mergeNode(res, temp);
        } else {
            int nstarted = 1;

            // skip
            Node temp1 = f(pos + 1, last, mask, nstarted, ntightL, ntightR);
            res = mergeNode(res, temp1);

            // take
            if (last == -1 || d > last) {
                int nmask = mask | (1 << d);
                Node temp2 = f(pos + 1, d, nmask, nstarted, ntightL, ntightR);
                res = mergeNode(res, temp2);
            }
        }
    }

    vis[pos][last + 1][mask][started][tightL][tightR] = true;
    return dp[pos][last + 1][mask][started][tightL][tightR] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        ll x, y;
        cin >> x >> y;

        L = to_string(x);
        R = to_string(y);

        // pad L with leading zeros
        while (L.size() < R.size()) L = "0" + L;

        memset(vis, 0, sizeof(vis));

        Node ans = f(0, -1, 0, 0, 1, 1);

        cout << "Case " << tc << ": " << ans.len << " " << ans.ways << "\n";
    }

    return 0;
}
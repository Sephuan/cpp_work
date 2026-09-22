#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

void solve() {
    int n; 
    if (!(cin >> n)) return;
    vector<int> a(n + 1);
    rep1(i, 1, n) cin >> a[i];
    
    vector<int> mx_pos(n + 1);
    int preMx = 0, cur_mx_idx = 0;
    rep1(i, 1, n) {
        if (a[i] > preMx) {
            preMx = a[i];
            cur_mx_idx = i;
        }
        mx_pos[i] = cur_mx_idx;
    }
    
    vector<int> mn_pos(n + 1);
    int preMn = 1e9, cur_mn_idx = 0;
    rrep(i, n, 1) {
        if (a[i] < preMn) {
            preMn = a[i];
            cur_mn_idx = i;
        }
        mn_pos[i] = cur_mn_idx;
    }

    ll ans = 0;
    Fenwick bit(n);

    vector<vector<int>> activate(n + 1);
    rep1(l, 1, n) {
        activate[mn_pos[l]].push_back(l);
    }
    rep1(r, 1, n) {
        for (int i : activate[r])
            bit.add(i, 1);
        ans += bit.query(mx_pos[r]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

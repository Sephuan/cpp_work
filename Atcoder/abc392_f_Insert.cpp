#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define AC return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

struct Fenwick {
    int n; vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}
    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int kth(int k) {
        int idx = 0;
        int mask = 1;
        while (mask << 1 <= n) mask <<= 1;
        for (int d = mask; d; d >>= 1) {
            int nxt = idx + d;
            if (nxt <= n && bit[nxt] < k) {
                k -= bit[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};

void init() {

}

void solve() {
    int N; cin >> N;
    vector<int> P(N + 1), ans(N + 1);
    rep1(i, 1, N) cin >> P[i];
    Fenwick fw(N);
    rep1(i, 1, N) fw.add(i, 1);
    rrep(i, N, 1) {
        int pos = fw.kth(P[i]);
        ans[pos] = i;
        fw.add(pos, -1);
    }
    rep1(i, 1, N) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
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

void init() {

}

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unite(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            fa[fx] = fy;
        }
    }
};

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n + 1);
    DSU dsu(n);
    rep1(i, 1, n) {
        cin >> p[i];
        if (i + x <= n) dsu.unite(i + x, i);
        if (i + y <= n) dsu.unite(i + y, i);
        if (i - x >= 1) dsu.unite(i - x, i);
        if (i - y >= 1) dsu.unite(i - y, i);
    }
    int f = 1;
    rep1(i, 1, n) {
        if (dsu.find(p[i]) != dsu.find(i)) {
            f = 0;
            break;
        }
    }
    cout << (f ? "Yes" : "No");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

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
    vector<int> fa, sz, mask;
    DSU(int n, string& s) : fa(n + 1), sz(n + 1, 1), mask(n + 1) {
        rep(i, 0, n) {
            iota(fa.begin(), fa.end(), 0);
            mask[i + 1] = 1 << s[i] - 'A';
        }
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
         if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        mask[x] |= mask[y];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    DSU dsu(n, s);
    vector<pii> rem, ans;
    ans.reserve(m);
    set<char> AB = {'A', 'B'};
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        if (AB.count(s[u - 1]) == AB.count(s[v - 1])) {
            if (dsu.unite(u, v)) ans.push_back({u, v});
        } else rem.push_back({u, v});
    }
    rep1(i, 1, n) {
        if (__builtin_popcount(dsu.mask[dsu.find(i)]) != 2) {
            cout << "No";
            return ;
        }
    }
    for (auto& [u, v] : rem) {
        if (ans.size() == n - 1) break;
        if (dsu.unite(u, v)) ans.push_back({u, v});
    }
    if (ans.size() < n - 1) {
        cout << "No";
    } else {
        cout << "Yes" << endl;
        rep(i, 0, n - 1) {
            auto& [u, v] = ans[i];
            cout << u << ' ' << v << endl;
        }
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

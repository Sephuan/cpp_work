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
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n;
    cin >> n;
    vector a(n + 1, 0);
    rep1(i, 1, n) cin >> a[i];
    vector g(n + 1, vector<int>());
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<int> path;
    vector<bool> ans(n + 1);
    auto dfs = [&](int u, int p, auto&& dfs_ref) -> void {
        if (path.count(a[u])) ans[u] = 1;
        else ans[u] = 0;
        path.insert(a[u]);
        for (auto& v : g[u]) {
            if (v != p) dfs_ref(v, u, dfs_ref);
        }
        path.erase(a[u]);
    };

    dfs(1, -1, dfs);
    rep1(i, 1, n) {
        if (ans[i]) cout << "Yes";
        else cout << "No";
        if (i < n) cout << '\n';
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

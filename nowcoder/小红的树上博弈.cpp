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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto dfs = [&](auto&& self, int u, int p) -> bool {
        if (u > 1 && g[u].size() == 1) {
            return 1;
        }
        int c = 0;
        for (int& v : g[u]) {
            if (v != p)
                c += self(self, v, u); 
        }
        return c >= 2;
    };
    for (int& v : g[1]) {
        if (dfs(dfs, v, 1)) {
            cout << "red";
            return ;
        }
    }
    cout << "purple";
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

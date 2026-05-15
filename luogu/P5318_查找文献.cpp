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

void init() {

}

void solve() {
    int n, m; cin >> n >> m;
    vector adj(n + 1, set<int>());
    rep(i, 0, m) {
        int x, y; cin >> x >> y;
        adj[x].insert(y);
    }
    vector mark(n + 1, 0);
    vector<int> ans1, ans2;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        if (!mark[u]) {
            mark[u] = 1;
            ans1.push_back(u);
        }
        for (auto& t : adj[u]) {
            if (!mark[t] && t != u) {
                self(self, t, u);
            }
        }
    };
    dfs(dfs, 1, 0);
    queue<int> q;
    fill(mark.begin(), mark.end(), 0);
    q.push(1);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        if (!mark[t]) {
            mark[t] = 1;
            ans2.push_back(t);
            for (auto& v : adj[t]) {
                if (!mark[v] && v != t) q.push(v);
            }
        }
    }
    rep(i, 0, ans1.size()) {
        if (i) cout << ' ';
        cout << ans1[i];
    }
    cout << '\n';
    rep(i, 0, ans2.size()) {
        if (i) cout << ' ';
        cout << ans2[i];
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

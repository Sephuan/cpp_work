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
#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3fLL;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

int getCand(int dis, int p, int k) {
    if (dis == LINF) return LINF;
    int d = dis;
    int mul = (d + k - 1) / k;
    if (k & 1) {
        if ((mul & 1) != p) {
            mul ++;
        }
    } else if (p) return LINF;
    return mul * k;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n + 1, vector<int>());
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        if (u != v) {
            g[v].push_back(u);
        }
    }
    vector dist(n + 1, vector<int>(2, LINF));
    queue<pii> q;
    dist[1][0] = 0;
    q.emplace(1, 0);
    while (!q.empty()) {
        auto& [u, p] = q.front(); q.pop();
        int nxtP = p ^ 1;
        for (int& v : g[u]) {
            if (dist[v][nxtP] != LINF) continue;
            dist[v][nxtP] = dist[u][p] + 1;
            q.emplace(v, nxtP);
        }
    }
    rep1(u, 1, n) {
        int ans = LINF;
        ans = min({
            ans, 
            getCand(dist[u][0], 0, k),
            getCand(dist[u][1], 1, k)
        });
        if (u > 1) cout << ' ';
        if (ans == LINF) cout << -1;
        else cout << ans;
    }
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

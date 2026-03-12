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

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, -1));
    auto org = g;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    while (a--) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 0;
        pq.push({0, {x, y}});
    }
    while (b--) {
        int x, y, t;
        cin >> x >> y >> t;
        org[x][y] = t;
    }
    while (!pq.empty()) {
        auto [t, p] = pq.top();
        auto [x, y] = p;
        pq.pop();
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx == 0 || ny == 0 || nx > n || ny > m)
                continue;

            if (g[nx][ny] == -1) {
                if (org[nx][ny]) {
                    g[nx][ny] = max(t + 1, org[nx][ny]);
                    pq.push({g[nx][ny], {nx, ny}});
                } else {
                    g[nx][ny] = t + 1;
                    pq.push({t + 1, {nx, ny}});
                }
            } else {
                if (org[nx][ny]) {
                    if (org[nx][ny] < t + 1)
                        g[nx][ny] = min(g[nx][ny], t + 1);
                } else {
                    g[nx][ny] = min(g[nx][ny], t + 1);
                }
            }
        }
    }
    int ans = -1;
    rep1(i, 1, n) rep1(j, 1, m) ans = max(ans, g[i][j]);
    cout << ans; 
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

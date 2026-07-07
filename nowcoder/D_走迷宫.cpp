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
const int MAXN = 1'000'005;

void init() {

}

void solve() {
    int n, m; cin >> n >> m;
    int a, b; cin >> a >> b;
    char g[n + 1][m + 1];
    int sx, sy, ex, ey;
    vector pre(n + 1, vector<int>(m + 1, 0));
    vector wall(n + 1, vector<int>(m + 1, 0));
    vector mark(n + 1, vector<int>(m + 1, false));
    rep1(i, 1, n) rep1(j, 1, m) {
        cin >> g[i][j];
        if (g[i][j] == 'S') sx = i, sy = j;
        if (g[i][j] == 'E') ex = i, ey = j;
        if (g[i][j] == '#') wall[i][j] = 1;
    }
    rep1(i, 1, n) rep1(j, 1, m) {
        pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + wall[i][j];
    }
    auto chk = [&](int cx, int cy) {
        if (cx < 1 || cy < 1 || cx + a - 1 > n || cy + b - 1 > m) return false;
        return pre[cx + a - 1][cy + b - 1] - pre[cx + a - 1][cy - 1] - pre[cx - 1][cy + b - 1] + pre[cx - 1][cy - 1] == 0;
    };
    if (chk(sx, sy) && chk(ex, ey)) {
        queue<pii> q;
        q.push({sx, sy});
        mark[sx][sy] = true;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == ex && y == ey) {
                cout << "YES";
                return ;
            }
            rep(i, 0, 4) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (chk(nx, ny) && !mark[nx][ny]) {
                    q.push({nx, ny});
                    mark[nx][ny] = true;
                }
            }
        }
    }
    cout << "NO";
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

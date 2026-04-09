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
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int M;
    cin >> M;
    vector g(310, vector<int>(310, INF));
    rep(i, 0, M) {
        int x, y, t;
        cin >> x >> y >> t;
        g[x][y] = min(g[x][y], t);
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0) {
                g[nx][ny] = min(g[nx][ny], t);
            }
        }
    }
    if (g[0][0] == 0) {
        cout << -1;
        return ;
    }
    int ans = INF;
    bool mark[310][310];
    memset(mark, 0, sizeof(mark));
    struct point {
        int x, y, t;
    };
    queue<point> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto [x, y, t] = q.front(); q.pop();
        if (g[x][y] == INF) {
            ans = min(ans, t);
            break;
        }
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0)
                continue;
            if (!mark[nx][ny] && t + 1 < g[nx][ny]) {
                mark[nx][ny] = 1;
                q.push({nx, ny, t + 1});
            }
        }
    }
    cout << (ans == INF ? -1 : ans);
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

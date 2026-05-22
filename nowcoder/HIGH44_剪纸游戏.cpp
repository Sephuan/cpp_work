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
    char g[1'005][1'005];
    rep1(i, 1, n) rep1(j, 1, m) cin >> g[i][j];
    auto bfs = [&](int x, int y) {
        int minx = x, miny = y, maxx = x, maxy = y;
        queue<pii> q; q.push({x, y});
        g[x][y] = '-';
        int cnt = 0;
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            cnt ++;
            minx = min(minx, cx), miny = min(miny, cy), maxx = max(maxx, cx), maxy = max(maxy, cy);         
            rep(i, 0, 4) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] != '.')
                    continue;
                q.push({nx, ny});
                g[nx][ny] = '-';
            }
        }
        int area = (maxx - minx + 1) * (maxy - miny + 1);
        return cnt == area;
    };
    int ans = 0;
    rep1(i, 1, n) rep1(j, 1, m) {
        if (g[i][j] == '.') {
            ans += bfs(i, j);
        }
    }
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

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
constexpr int dy[] = {0, 0, 1, -1};

void solve_1() {
    int R, C;
    cin >> R >> C;
    int a[105][105];
    int memo[105][105];
    memset(memo, 0, sizeof(memo));
    rep1(i, 1, R) rep1(j, 1, C)
        cin >> a[i][j];

    int ans = 1;
    auto dfs = [&](auto& self, int x, int y) -> int {
        if (memo[x][y]) return memo[x][y];
        memo[x][y] = 1;
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == 0 || ny == 0 || nx > R || ny > C)
                continue;
            if (a[nx][ny] < a[x][y])
                memo[x][y] = max(memo[x][y], self(self, nx, ny) + 1);
        }
        return memo[x][y];
    };
    rep1(i, 1, R) rep1(j, 1, C)
        ans = max(ans, dfs(dfs, i, j));
    cout << ans;
}

void solve_2() {
    int R, C;
    cin >> R >> C;
    struct Point {
        int x, y, h;
        bool operator<(const Point& other) const {
            return h < other.h;
        }
    };
    vector<Point> pts;
    int a[105][105];
    int dp[105][105];
    rep1(i, 1, R) rep1(j, 1, C) {
        cin >> a[i][j];
        dp[i][j] = 1;
        pts.push_back({i, j, a[i][j]});
    }
    sort(pts.begin(), pts.end());
    int ans = 1;
    for (auto& p : pts) {
        int x = p.x;
        int y = p.y;
        int h = p.h;
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == 0 || ny == 0 || nx > R || ny > C)
                continue;
            if (a[nx][ny] > h)
                dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
            ans = max(ans, dp[nx][ny]);
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
        solve_2();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

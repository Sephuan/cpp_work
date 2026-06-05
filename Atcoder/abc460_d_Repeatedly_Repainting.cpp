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
constexpr int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int H, W;
    cin >> H >> W;
    vector g(H + 1, vector<char>(W + 1));
    vector mark_w(H + 1, vector<int>(W + 1, 0));
    vector mark_b = mark_w;
    queue<pii> qb, qw;
    rep1(i, 1, H) rep1(j, 1, W) {
        cin >> g[i][j];
        if (g[i][j] == '#') qb.push({i, j});
        else qw.push({i, j});
    }
    if (qw.size() == H * W || qb.size() == H * W) {
        rep1(i, 1, H) rep1(j, 1, W) {
            cout << '.';
            if (j == W) cout << endl;
        }
        return ;
    }
    while (!qb.empty()) {
        auto [x, y] = qb.front(); qb.pop();
        rep(i, 0, 8) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > H || ny > W) continue;
            if (g[nx][ny] == '#' || mark_w[nx][ny]) continue;
            mark_w[nx][ny] = mark_w[x][y] + 1;
            qb.push({nx, ny});
        }
    }
    while (!qw.empty()) {
        auto [x, y] = qw.front(); qw.pop();
        rep(i, 0, 8) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > H || ny > W) continue;
            if (g[nx][ny] == '.' || mark_b[nx][ny]) continue;
            mark_b[nx][ny] = mark_b[x][y] + 1;
            qw.push({nx, ny});
        }
    }
    rep1(i, 1, H) rep1(j, 1, W) {
        if (g[i][j] == '.' && mark_w[i][j] % 2 == 0) cout << '#';
        else if (g[i][j] == '#' && mark_b[i][j] % 2 == 0) cout << '.';
        else cout << g[i][j];
        if (j == W) cout << endl;
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

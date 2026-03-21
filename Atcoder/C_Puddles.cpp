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

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

void init() {

}

char g[1'005][1'005];
bitset<1'000'005> b;
int cnt = 0;
void solve() {
    int H, W;
    cin >> H >> W;
    rep1(i, 1, H) rep1(j, 1, W) {
        cin >> g[i][j];
    }
    auto dfs = [&](auto& self, int sx, int sy) -> void {
        g[sx][sy] = '#';
        if (sx == 1 || sy == 1 || sx == H || sy == W)
            b[cnt] = 1;
        rep(i, 0, 4) {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if (nx < 1 || ny < 1 || nx > H || ny > W)
                continue;
            if (g[nx][ny] == '.') self(self, nx, ny);
        }
    };
    rep1(i, 1, H) rep1(j, 1, W) {
        if (g[i][j] == '.') {
            cnt ++;
            dfs(dfs, i, j);
        }
    }
    int ans = cnt;
    rep1(i, 1, cnt) {
        if (b[i]) ans --;
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

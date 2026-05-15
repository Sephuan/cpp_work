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

int g[31][31];
int mark[1'000];
void solve() {
    int n; cin >> n;
    int cnt = 3;
    rep1(i, 1, n) rep1(j, 1, n) cin >> g[i][j];
    auto dfs = [&](auto&& self, int x, int y) -> void {
        g[x][y] = cnt;
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > n) {
                mark[cnt] = 1;
                continue;
            }
            if (g[nx][ny]) continue;
            self(self, nx, ny);
        }
    };
    rep1(i, 1, n) rep1(j, 1, n) {
        if (!g[i][j]) {
            dfs(dfs, i, j);
            cnt ++;
        }
    }
    rep1(i, 1, n) rep1(j, 1, n) {
        if (g[i][j] == 0) cout << 0;
        else if (mark[g[i][j]]) cout << 0;
        else cout << min(2, g[i][j]);
        cout << " \n"[j == n];
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

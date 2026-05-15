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
constexpr int dx[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
constexpr int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};


const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int tx, ty, hx, hy;
    cin >> tx >> ty >> hx >> hy;
    vector dp(21, vector(21, -1LL));
    rep(i, 0, 9) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        if (nx >= 0 && nx <= tx && ny >= 0 && ny <= ty)
        dp[nx][ny] = 0;
    }
    dp[0][0] = 1;
    rep1(i, 0, tx) rep1(j, 0, ty) {
        if (i == 0 && j == 0) continue;
        if (!dp[i][j]) continue;
        dp[i][j] = 0;
        if (i - 1 >= 0) dp[i][j] += max(0LL, dp[i - 1][j]);
        if (j - 1 >= 0) dp[i][j] += max(0LL, dp[i][j - 1]);
    }
    cout << dp[tx][ty];
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

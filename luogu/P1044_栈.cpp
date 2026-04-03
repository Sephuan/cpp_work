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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n;
    cin >> n;
    /*
    auto dfs = [&](auto&& self, int r, int c) {
        if (r == 0) return 1;
        int sum = 0;
        if (c > 0) sum += self(self, r , c - 1);
        if (r > 0) sum += self(self, r - 1, c + 1);
        return sum;
    };
    */
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    rep1(i, 0, n) dp[0][i] = 1;
    rep1(i, 1, n) rep1(j, 0, n) {
        if (j + 1 <= n)
            dp[i][j] += dp[i - 1][j + 1];
        if (j > 0)
            dp[i][j] += dp[i][j - 1];
    }
    cout << dp[n][0];
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

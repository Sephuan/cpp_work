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
    ll L[n + 1], R[n + 1];
    rep1(i, 1, n) cin >> L[i] >> R[i];
    ll dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = R[1] - 1 + R[1] - L[1];
    dp[1][1] = R[1] - 1;
    rep1(i, 2, n) {
        dp[i][0] = min(dp[i - 1][0] + abs(R[i] - L[i - 1]), dp[i - 1][1] + abs(R[i] - R[i - 1])) + 1 + R[i] - L[i];
        dp[i][1] = min(dp[i - 1][0] + abs(L[i] - L[i - 1]), dp[i - 1][1] + abs(L[i] - R[i - 1])) + 1 + R[i] - L[i];
    }
    cout << min(dp[n][0] + n - L[n], dp[n][1] + n - R[n]);
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

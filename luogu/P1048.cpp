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

vector<pii> vp(1'05);

void solve_1() {
    int T, M;
    cin >> T >> M;
    int dp[105][1'005];
    memset(dp, -1, sizeof(dp));
    rep1(i, 1, M)
        cin >> vp[i].fi >> vp[i].se;
    auto dfs = [&](auto& self, int idx, int rem_t) -> int {
        if (idx > M) return 0;
        if (dp[idx][rem_t] != -1) return dp[idx][rem_t];

        auto& [t, v] = vp[idx];
        int res = self(self, idx + 1, rem_t);
        if (rem_t >= t)
            res = max(res, self(self, idx + 1, rem_t - t) + v);
        return dp[idx][rem_t] = res;
    };
    cout << dfs(dfs, 1, T);
}

void solve_2() {
    int T, M;
    cin >> T >> M;
    int dp[1'005];
    memset(dp, 0, sizeof(dp));
    rep1(i, 1, M) {
        int t, v;
        cin >> t >> v;
        rrep(j, T, t)
            dp[j] = max(dp[j], dp[j - t] + v);
    }
    cout << dp[T];
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

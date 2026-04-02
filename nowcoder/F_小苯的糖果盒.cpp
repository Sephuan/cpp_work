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
    vector<int> s(n + 1, 0);
    rep1(i, 1, n) {
        int a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    vector dp(n + 1, vector<int>(s[n] + 1, INF));
    dp[0][0] = 0;
    for (int p = 0; p * p <= s[n]; ++p) {
        int x = p * p;
        rep1(i, 1, n) {
            rep1(j, x, s[n]) {
                dp[i][j] = min(
                    dp[i][j], 
                    dp[i - 1][j - x] + abs(s[i] - j)
                );
            }
        }
    }
    cout << (dp[n][s[n]] == INF ? -1 : dp[n][s[n]]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

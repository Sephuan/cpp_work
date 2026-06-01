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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int dp[3] = {0, 0, 0};
    int ans = 0;
    rep(i, 0, n) {
        int d = s[i] ^ 48;
        int r = d % 3;
        if (d % 2 == 0) {
            ans += dp[(3 - r) % 3];
            ans %= MOD;
            if (r == 0) ans += 1;
        }
        int tdp[3]; rep(i, 0, 3) {
            int idx = (i + r) % 3;
            tdp[idx] = dp[idx] + dp[i];
            tdp[idx] %= MOD;
        }
        rep(i, 0, 3) dp[i] = tdp[i];
        dp[r] += 1;
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

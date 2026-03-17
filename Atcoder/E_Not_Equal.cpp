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
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(5, LLONG_MAX / 4));
    vector v_j = {-2, -1, 0, 1, 2};
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    rep1(i, 1, n) cin >> a[i];
    rep1(i, 1, n) cin >> b[i];
    rep1(i, 1, n) cin >> c[i];
    rep(i, 0, 5) {
        if (i < 2) {
            if (a[1] + v_j[i] < 1) dp[1][i] = LLONG_MAX / 4;
            else dp[1][i] = c[1] * (-v_j[i]);
        } else dp[1][i] = b[1] * v_j[i];
    }
    rep1(i, 2, n) rep(j, 0, 5) {
        ll t_a = a[i] + v_j[j];
        if (t_a < 1) {
            dp[i][j] = LLONG_MAX / 4;
            continue;
        }
        rep(k, 0, 5) {
            if (a[i - 1] + v_j[k] == t_a) continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j < 2 ? -v_j[j] * c[i] : v_j[j] * b[i]));
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end());
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

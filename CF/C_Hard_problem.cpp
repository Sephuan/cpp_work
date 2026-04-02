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
const int MAXN = 1'00'005;

void init() {

}

int n;
string s[MAXN], rs[MAXN];
ll dp[MAXN][2];
ll c[MAXN];
void solve() {
    cin >> n;
    rep1(i, 1, n) {
        cin >> c[i];
    }
    rep1(i, 1, n) {
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(), rs[i].end());
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    dp[1][1] = c[1];
    rep1(i, 2, n) {
        if (s[i] >= s[i - 1])
            dp[i][0] = dp[i - 1][0];
        if (s[i] >= rs[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (rs[i] >= s[i - 1])
            dp[i][1] = dp[i - 1][0] + c[i];
        if (rs[i] >= rs[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]); 
    }
    ll ans = min(dp[n][0], dp[n][1]);
    cout << (ans > 1e18 ? -1 : ans);
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

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
    vector<int> a(n + 1), dp(n + 1, INF), p_xor(n + 1, 0);
    rep1(i, 1, n) {
        cin >> a[i];
        p_xor[i] = a[i] ^ p_xor[i - 1];
    }
    dp[0] = 0;
    rep1(i, 1, n) {
        rep(j, 0, i) {
            dp[i] = min(dp[j] + (p_xor[i] ^ p_xor[j]), dp[i]);
            dp[j] = min(dp[j], dp[i]);
        }
    }
    cout << dp[n];
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

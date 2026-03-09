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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector pal(n + 1, vector(n + 1, 0));
    vector dp(n + 1, 0LL);
    vector cnt(n + 1, 0LL);
    cnt[0] = 1;
    rep1(i, 1, n) rep1(j, 1, i) {
        if (s[i] == s[j] && (i - j <= 1 || pal[i - 1][j + 1])) {
            pal[i][j] = 1;
            int L = i - j + 1;
            cnt[i] = (cnt[i] + cnt[j - 1]) % MOD;
            dp[i] = ((dp[i] + dp[j - 1]) % MOD + cnt[j - 1] * L % MOD * L % MOD) % MOD;        
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

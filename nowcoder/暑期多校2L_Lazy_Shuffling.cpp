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
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    vector<int> r(n);
    rep(i, 0, n) {
        r[p[i] - 1] = i;
    }
    vector<int> pre(n);
    int m = 0;
    rep(i, 0, n - 1) rep(j, i + 1, n) {
        if (r[i] > r[j]) {
            m ++;
            pre[i] |= 1 << j;
        }
    }
    if (m == 0) {
        ll fact = 1;
        rep1(i, 2, n) fact = fact * i % MOD;
        cout << fact;
        return ;
    }
    int FULL = (1 << n) - 1;
    vector<int> dp(FULL + 1, 0);
    dp[0] = 1;
    rep(mask, 0, FULL) {
        if (dp[mask] == 0) continue;
        int rest = FULL ^ mask;
        while (rest > 0) {
            int bit = rest & -rest;
            int i = __builtin_ctz(bit);
            if ((pre[i] & mask) == pre[i]) {
                int nxtMask = mask | bit;
                int val = dp[nxtMask] + dp[mask];
                if (val >= MOD) val -= MOD;
                dp[nxtMask] = val;
            }
            rest -= bit;
        }
    }
    cout << 2LL * dp[FULL] % MOD;
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

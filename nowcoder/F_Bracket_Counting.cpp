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
    vector<ll> dp(1 << n, 0);
    dp[0] = 1;
    vector<int> min_r(n), bal(n);
    vector<int> sum_bal(1 << n);
    int tot_bal = 0;
    rep(i, 0, n) {
        string s; cin >> s;
        for (char& c : s) {
            if (c == '(') bal[i] ++;
            else {
                bal[i] --;
                min_r[i] = min(min_r[i], bal[i]);
            }
        }
        tot_bal += bal[i];
    }
    if (tot_bal != 0) {
        cout << 0;
        return ;
    }
    rep(i, 0, 1 << n) {
        if (dp[i] == 0) continue;
        rep(j, 0, n) {
            if ((i & (1 << j)) != 0) continue;
            int nxt = i | (1 << j);
            sum_bal[nxt] = sum_bal[i] + bal[j];
            if (sum_bal[i] + min_r[j] >= 0) {
                dp[nxt] += dp[i];
                dp[nxt] %= mod;
            }
        }
    }
    cout << dp[(1 << n) - 1];
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

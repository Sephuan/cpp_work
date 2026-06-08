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
constexpr int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 1'000'005;


vector<int> dp(MAXN, 1);
vector<int> lst_pos(MAXN);
vector<int> spf(MAXN);

void init() {
    dp[0] = 0;
    rep(i, 2, MAXN) {
        if (!spf[i]) {
            for (int j = i; j < MAXN; j += i) {
                spf[j] = i;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    rep1(i, 1, n) cin >> a[i];
    rep1(i, 1, n) {
        vector<int> ps;
        int x = a[i];
        while (x > 1) {
            int tp = spf[x];
            ps.push_back(tp);
            while (x % tp == 0) x /= tp;
        }
        if (x > 1) ps.push_back(x);
        for (int p : ps) {
            if (dp[lst_pos[a[i] / p]] + 1 > dp[i]) {
                dp[i] = dp[lst_pos[a[i] / p]] + 1;
                pre[i] = lst_pos[a[i] / p];
            }
        }
        lst_pos[a[i]] = i;
    }
    int ans = 0;
    rep1(i, 1, n) {
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }
    cout << ans << endl;
    int ini = 0;
    rrep(i, n, 1) {
        if (dp[i] == ans) {
            ini = i;
            break;
        }
    }
    vector<int> res = {a[ini]};
    while (pre[ini]) {
        res.push_back(a[pre[ini]]);
        ini = pre[ini];
    }
    sort(res.begin(), res.end());
    rep(i, 0, res.size()) {
        if (i) cout << ' ';
        cout << res[i];
    }
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

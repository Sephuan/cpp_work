#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define Sephuan return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3fLL;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 200'005;

void init() {

}

void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1);
    map<int, int> r_to_l, r_to_id;
    vector<pii> seg_d_r;
    rep1(i, 1, n) {
        int l, r;
        cin >> l >> r >> w[i];
        r_to_l[r] = l;
        r_to_id[r] = i;
        seg_d_r.emplace_back(r - l, r);
    }
    ranges::sort(seg_d_r);
    vector<ll> dp(2 * n + 1);
    map<int, ll> id_val;
    function<ll(int, int)> run_dp = [&](int l, int r) -> ll {
        if (l >= r) return 0;
        dp[l - 1] = 0;
        rep1(i, l, r) {
            dp[i] = dp[i - 1];
            if (r_to_l.count(i)) {
                int cl = r_to_l[i];
                if (cl >= l) {
                    dp[i] = max(dp[i], dp[cl - 1] + id_val[r_to_id[i]]);
                }
            }
        }
        return dp[r];
    };
    for (auto& [d, r] : seg_d_r) {
        id_val[r_to_id[r]] = run_dp(r_to_l[r] + 1, r - 1) + w[r_to_id[r]];
    }
    cout << run_dp(1, 2 * n);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    Sephuan
}

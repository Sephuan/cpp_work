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
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, 0);
    ll att, pri, cost, upg, lvm;
    rep1(i, 1, n) {
        vector<pll> comb;
        cin >> att >> pri >> cost >> upg >> lvm;
        rep1(j, 0, lvm) {
            ll tot_cost = pri + j * cost;
            ll tot_att = att + j * upg;
            if (tot_cost > x) break;
            comb.push_back({tot_cost, tot_att});
        }
        rrep(j, x, 1) {
            for (auto& [c, a] : comb) {
                if (c <= j) {
                    dp[j] = max(dp[j], dp[j - c] + a);
                }
            }
        }
    }
    cout << dp[x];
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

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

struct item {
    int v, p;
    int s;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<item>> vvi(m + 1);
    vector<item> mi(m + 1, {-1, 0, 0});
    rep1(i, 1, m) {
        int v, p, q;
        cin >> v >> p >> q;
        if (q) vvi[q].push_back({v, p, v * p});
        else mi[i] = {v, p, v * p};
    }
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    rep1(i, 1, m) {
        if (mi[i].v == -1) {
            continue;
        }
        vector<item> comb;
        comb.push_back(mi[i]);
        if (vvi[i].size() > 0) {
            comb.push_back({
                mi[i].v + vvi[i][0].v, 
                0,
                mi[i].s + vvi[i][0].s
            });
        }
        if (vvi[i].size() > 1) {
            comb.push_back({
                mi[i].v + vvi[i][1].v,
                0,
                mi[i].s + vvi[i][1].s
            });
            comb.push_back({
                mi[i].v + vvi[i][0].v + vvi[i][1].v,
                0,
                mi[i].s + vvi[i][0].s + vvi[i][1].s
            });
        }
        rrep(j, n, 0) {
            for (auto& c : comb) {
                if (c.v <= j) {
                    dp[j] = max(dp[j], dp[j - c.v] + c.s);
                }
            }
        }
    }
    cout << dp[n];
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

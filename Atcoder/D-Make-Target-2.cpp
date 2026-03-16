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
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    auto cal = [](ll x, ll y) {
        if (x < 0 || y < 0) return 0LL;
        if (x > y) swap(x, y);
        ll c1 = (2 + (x >> 1 << 2)) * (x + 2 >> 1) >> 1;
        ll c2 = (y - x + (x & 1 ? 1 : 0) >> 1) * (x + 1);
        return c1 + c2;
    };
    auto f = [&](ll x1, ll y1, ll x2, ll y2) {
        return cal(x2, y2) - cal(x1 - 1, y2) - cal(x2, y1 - 1) + cal(x1 - 1, y1 - 1);
    };
    auto get_pair = [&](ll a, ll b) {
        vector<pll> res;
        if (a >= 0) res.push_back({a, b});
        else if (b < 0) res.push_back({-b, -a});
        else {
            res.push_back({0, b});
            res.push_back({1, -a});
        }
        return res;
    };
    ll L, R, D, U;
    ll ans = 0;
    cin >> L >> R >> D >> U;

    vector<pll> X_p = get_pair(L, R);
    vector<pll> Y_p = get_pair(D, U);
    for (auto [x1, x2] : X_p) {
        for (auto [y1, y2] : Y_p) {
            ans += f(x1, y1, x2, y2);
        }
    }
    cout << ans;
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

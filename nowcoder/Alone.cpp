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

ll qpow(ll a, ll p) {
    ll r = 1;
    a %= MOD;
    while (p > 0) {
        if (p & 1) r = r * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return r;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    map<int, int> X, Y;
    vector<pii> a;
    rep(i, 0, k) {
        int x, y;
        cin >> x >> y;
        X[x] ++;
        Y[y] ++;
        a.push_back({x, y});
    }
    ll ans = (n - X.size()) * (m - Y.size()) % MOD * qpow(2, (n * m - k - n - m + 1) % MOD_P) % MOD;
    for (auto& p : a) {
        ans += (X[p.fi] == 1 && Y[p.se] == 1 ? qpow(2, n * m - k + 1- m - n + 1) : 0);
        ans %= MOD;
    }
    cout << ans;
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

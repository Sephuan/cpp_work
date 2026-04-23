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
const int MAXN = 1'005;

ll fact[MAXN], inv_fact[MAXN];
ll qpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

void init() {

}

void solve() {
    int n; cin >> n;
    ll sum = 0;
    ll c1 = 0, c2 = 0, c3 = 0;
    rep(i, 0, n) {
        int t; cin >> t;
        if (t == 1) c1 ++;
        else if (t == 2) c2 ++;
        else c3 ++;
    }
    auto f = [](ll x) -> ll {
        if (x == 0) return 1;
        return qpow(2, x - 1) * (x + 2) % mod;
    };
    cout << (qpow(2, c1) * f(c2) % mod * f(c3) - 1 + mod) % mod;
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

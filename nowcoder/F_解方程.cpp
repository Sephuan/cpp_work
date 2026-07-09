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
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

ll qpow(ll a, ll p) {
    ll r = 1;
    p %= mod;
    while (p) {
        if (p & 1) r = r * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return r;
}

vector<ll> fact(MAXN), invf(MAXN);
void init() {
    fact[0] = 1;
    rep(i, 1, MAXN) fact[i] = fact[i - 1] * i % mod;
    invf[MAXN - 1] = qpow(fact[MAXN - 1], mod - 2);
    rrep(i, MAXN - 1, 1) invf[i - 1] = invf[i] * i % mod;
}

ll C(ll a, ll b) {
    if (b < 0 || b > a) return 0LL;
    return fact[a] * invf[b] % mod * invf[a - b] % mod;
}

void solve() {
    int n; cin >> n;
    vector<int> c(MAXN, 0);
    rep(i, 0, n) {
        int x; cin >> x;
        c[x] ++;
    }
    vector<int> cnt(MAXN, 0);
    rep(d, 1, MAXN) {
        int s = 0;
        for (int m = d; m < MAXN; m += d) s += c[m];
        cnt[d] = s;
    }
    vector<int> best(n + 1, 0);
    rep(d, 1, MAXN) {
        if (cnt[d] >= 1) best[cnt[d]] = max(best[cnt[d]], d);
    }
    rrep(k, n - 1, 1) {
        best[k] = max(best[k], best[k + 1]);
    }
    int q; cin >> q;
    while (q --) {
        int k; cin >> k;
        int g = best[k];
        cout << C(cnt[g], k) << endl;
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

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
const int MAXN = 1'00'005;

ll fact[MAXN], inv_fact[MAXN];

ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b > 0) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll modInv(ll n, ll p) {
    return qpow(n, p - 2, p);
}

void init(ll p) {
    fact[0] = inv_fact[0] = 1;
    rep(i, 1, p) fact[i] = fact[i - 1] * i % p;
    inv_fact[p - 1] = modInv(fact[p - 1], p);
    rrep(i, p - 2, 1) inv_fact[i] = inv_fact[i + 1] * (i + 1) % p;
}

ll C(ll n, ll m, ll p) {
    if (m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1;
    return fact[n] * inv_fact[m] % p * inv_fact[n - m] % p;
}

ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    init(p);
    cout << lucas(n + m, m, p);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //init();
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

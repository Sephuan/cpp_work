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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

ll fact[MAXN];

void init() {
    fact[0] = 1;
    rep(i, 1, MAXN) {
        fact[i] = fact[i - 1] * i % MOD;
    }
}

ll qpow(ll a, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1) r = r * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return r;
}

ll inv(ll n) {
    return qpow(n, MOD - 2);
}

ll A(ll n, ll m) {
    if (n < m) return 0;
    else if (m == 0) return 1;
    else return fact[n] * inv(fact[n - m]) % MOD;
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    ll odd = 0, even = 0;
    odd = n + 1 >> 1;
    even = n >> 1;
    ll cnt_o = 0, cnt_e = 0, cnt_r = 0;
    for (char c : s) {
        if (c == 'j') cnt_o ++;
        else if (c == 'o') cnt_e ++;
        else cnt_r ++;
    }
    if (cnt_o > odd || cnt_e > even) cout << 0;
    else cout << A(odd, cnt_o) * A(even, cnt_e) % MOD * A(n - cnt_o - cnt_e, cnt_r) % MOD; 
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

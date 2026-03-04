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

const int MAXN = 2'00'005;

namespace FastIO {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline char gc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    inline int read() {
        int x = 0; char c = gc();
        while (c < '0' || c > '9') c = gc();
        while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = gc();}
        return x;
    }
}
using FastIO::read;

void init() {

}

ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
    }
    return res;
}

void solve() {
    int n = read();
    ll p = read();
    ll k = read();
    
    vector<ll> a(n + 1), s(n + 1), sv(n + 1);
    s[0] = 1;
    rep1(i, 1, n) {
        a[i] = read();
        s[i] = s[i - 1] * a[i] % p;
    }
    sv[n] = qpow(s[n], p - 2, p);
    rrep(i, n, 1) {
        sv[i - 1] = sv[i] * a[i] % p;
    }

    ll ans = 0;
    ll cur_k = k;
    rep1(i, 1, n) {
        ll inv_a = sv[i] * s[i - 1] % p;
        ans = (ans + inv_a * cur_k) % p;
        cur_k = cur_k * k % p;
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

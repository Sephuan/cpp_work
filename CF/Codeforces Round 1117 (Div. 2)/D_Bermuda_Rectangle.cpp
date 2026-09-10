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

template <int MOD>
struct ModInt {
    int v;

    ModInt() : v(0) {}
    ModInt(__int128 _v) {
        v = static_cast<int>(_v % MOD);
        if (v < 0) v += MOD;
    }

    ModInt power(long long p) const {
        ModInt res = 1, base = *this;
        while (p > 0) {
            if (p & 1) res *= base;
            base *= base;
            p >>= 1;
        }
        return res;
    }

    ModInt inv() const { return power(MOD - 2); }

    ModInt& operator+=(const ModInt& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& o) {
        v = static_cast<int>(1LL * v * o.v % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& o) {
        return *this *= o.inv();
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

    bool operator==(const ModInt& o) const { return v == o.v; }
    bool operator!=(const ModInt& o) const { return v != o.v; }

    friend istream& operator>>(istream& is, ModInt& x) {
        long long val;
        is >> val;
        x = ModInt(val);
        return is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& x) {
        return os << x.v;
    }
};
using MI_1e9 = ModInt<1000000007>;
using MI_998 = ModInt<998244353>;
using MI = MI_998;

void init() {

}

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return ;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        p[v] = p[u];
    }
};

void solve() {
    ll S; int q; cin >> S >> q;
    vector<ll> facs{0}, larger;
    for (ll i = 1; i * i <= S; ++ i) {
        if (S % i == 0) {
            facs.push_back(i);
            if (i * i != S) larger.push_back(S / i);
        }
    }
    rrep(i, larger.size() - 1, 0) facs.push_back(larger[i]);
    int m = facs.size() - 1;
    vector<ll> pre(m + 1);
    rep1(i, 1, m) {
        ll w = facs[i] - facs[i - 1];
        ll h = S / facs[i];
        pre[i] = pre[i - 1] + h * w;
    }
    while (q --) {
        ll x, y; cin >> x >> y;
        int k = upper_bound(facs.begin(), facs.end(), S / y)
            - facs.begin() - 1;
        if (x <= facs[k]) {
            cout << x * y;
            if (q) cout << endl;
            continue;
        }
        ll s1 = facs[k] * y;
        int r = lower_bound(facs.begin(), facs.end(), x)
            - facs.begin();
        ll s2 = pre[r - 1] - pre[k];
        ll s3 = (x - facs[r - 1]) * (S / facs[r]);
        cout << s1 + s2 + s3;
        if (q) cout << endl;
    }
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
    Sephuan
}

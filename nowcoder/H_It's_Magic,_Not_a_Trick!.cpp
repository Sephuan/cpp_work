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
    int n;
    ll x; cin >> n >> x;
    MI sum = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;
    lll p = 0;
    rep(i, 0, n) {
        ll a; cin >> a;
        sum += a;
        if (a >= x) p += a / x;
        ll r = a % x;
        if (r) {
            ll c = x - 1 - r;
            pq.push(c);
        }
    }
    if (x == 1) {
        cout << sum;
        return ;
    }
    MI k = p;
    while (!pq.empty()) {
        ll c = pq.top(); pq.pop();
        if (p < c) break;
        p -= c;
        k += 1;
    }
    k += p / (x - 1);
    MI ans = sum - k * (x - 1);
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
    Sephuan
}

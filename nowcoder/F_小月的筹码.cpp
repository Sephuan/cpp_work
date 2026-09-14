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
constexpr int ddx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int ddy[] = {0, 0, -1, 1, -1, 1, 1, -1};
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
using MI = MI_1e9;

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

void init() {

}

void solve() {
    int n, k, x; cin >> n >> k >> x;
    MI ans = 0;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int mid = n >> 1;
    vector<unordered_map<int, int>> vum(n + 1);
    int FULL_L = 1 << mid;
    int FULL_R = 1 << (n - mid);

    vector<int> xor_s(FULL_L);
    vector<int> xor_s2(FULL_R);
    vum[0][0] = 1;
    rep(mask, 1, FULL_L) {
        int i = __builtin_ctz(mask);
        int c = __builtin_popcount(mask);
        xor_s[mask] = xor_s[mask ^ (1 << i)] ^ a[i];
        vum[c][xor_s[mask]] ++;
    }
    
    rep(mask, 0, FULL_R) {
        if (mask) {
            int i = __builtin_ctz(mask);
            xor_s2[mask] = xor_s2[mask ^ (1 << i)] ^ a[mid + i];
        }

        int c = __builtin_popcount(mask);
        int need = k - c;
        if (need >= 0 && need <= n - mid && vum[need].count(xor_s2[mask] ^ x)) {
            ans += vum[need][xor_s2[mask] ^ x];
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
    Sephuan
}

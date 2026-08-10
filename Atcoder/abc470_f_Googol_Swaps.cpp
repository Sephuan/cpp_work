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
    ModInt(long long _v) { 
        v = _v % MOD; 
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

    ModInt& operator+=(const ModInt& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    ModInt& operator-=(const ModInt& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    ModInt& operator*=(const ModInt& o) { v = 1LL * v * o.v % MOD; return *this; }
    ModInt& operator/=(const ModInt& o) { return *this *= o.inv(); } 

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

    bool operator==(const ModInt& o) const { return v == o.v; }
    bool operator!=(const ModInt& o) const { return v != o.v; }

    friend istream& operator>>(istream& is, ModInt& x) {
        long long val; is >> val; x = ModInt(val); return is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& x) {
        return os << x.v;
    }
};

using MI_1e9 = ModInt<1000000007>;
using MI_998 = ModInt<998244353>;
using MI = MI_998;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return ;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

vector<MI> fac(MAXN);
void init() {
    fac[0] = 1;
    rep(i, 1, MAXN) fac[i] = fac[i - 1] * i;
}

void solve() {
    int N, M; cin >> N >> M;
    string S; cin >> S;
    DSU dsu(N);
    rep(i, 0, M) {
        int A, B; cin >> A >> B;
        -- A, -- B;
        dsu.unite(A, B);
    }
    vector<array<int, 26>> cnt(N);
    vector<int> compSz(N);
    rep(i, 0, N) {
        int r = dsu.find(i);
        compSz[r] ++;
        cnt[r][S[i] - 'a'] ++;
    }
    MI P = 1, Q = 1;
    bool hasRepeat = false;
    rep(r, 0, N) {
        if (compSz[r] == 0) continue;
        int k = compSz[r];
        if (k >= 2) P = P * fac[k];
        rep(c, 0, 26) {
            int m = cnt[r][c];
            if (m >= 2) {
                hasRepeat = true;
                Q = Q * fac[m];
            }
        }
    }
    MI ans = P * Q.inv();
    MI t = 2;
    if (!hasRepeat) ans *= t.inv();
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

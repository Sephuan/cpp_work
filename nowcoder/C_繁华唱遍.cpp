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
#define all(x) (x).begin(), (x).end()
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
using MI = MI_998;

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

/*

pre !== S - pre (mod 3)
2 pre !== S     (mod 3)
pre !== 2 S     (mod 3)

S === 0:
    pre !== 0
    +1  |  +1  +2   +1 +2  +1  +2  | +2          | +1  + 1           |
    1   |  2   1    2  1    2   1  |  c1 == c2  |  c1 - c2 == 3     | 

    +2 | +2 +1 +2 +1 +2 | +2              | +1 +1 |
    2  | 1   2  1  2  1 | c2 - c1 == 3    |  c1 == c2 |
S === 1:
    pre !== 2
    +1 | +2 +1 +2 | +1 |      c1 == c2 + 1
    1 | 0   1  0 |  1  |

S === 2:
    pre != 1
    +2 | +1  +2  +1  | +2 |    c2 == c1 + 1
    2 |  0   2   0   | 2 |
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector c(3, vector<int>());
    int s = 0;
    rep(i, 0, n) {
        int a; cin >> a;
        c[a % 3].push_back(a);
        s += a % 3;
        s %= 3;
    }
    if (c[1].size() == c[2].size() && c[1].size() == 0) {
        cout << "NO";
        return ;
    }
    vector<int> out;
    if (s == 0) {
        if (
                c[1].size() == c[2].size() 
            ||  c[1].size() == 3 + c[2].size()
            ||  c[2].size() == 3 + c[1].size()
        ) {
            if (c[2].size() == 3 + c[1].size())
                swap(c[1], c[2]);
            int i = 0;
            out.push_back(c[1][i ++]);
            rep(k, 0, c[0].size()) out.push_back(c[0][k]);
            rep(j, 0, (int)c[2].size() - 1) {
                out.push_back(c[1][i ++]);
                out.push_back(c[2][j]);
            }
            if (c[1].size() == c[2].size())
                out.push_back(c[2].back());
            else {
                if (c[2].size()) {
                    out.push_back(c[1][i ++]);
                    out.push_back(c[2].back());
                }
                rep(k, 0, 2) out.push_back(c[1][i ++]);
            }
        } else {
            cout << "NO";
            return ;
        }
    } else {
        if (
                c[1].size() == c[2].size() 
            ||  c[1].size() == c[2].size() + 1
            ||  c[2].size() == c[1].size() + 1
        ) {
            if (c[2].size() == c[1].size() + 1)
                swap(c[2], c[1]);
            int i = 0;
            out.push_back(c[1][i ++]);
            rep(k, 0, c[0].size()) out.push_back(c[0][k]);
            rep(j, 0, c[2].size()) {
                out.push_back(c[2][j]);
                out.push_back(c[1][i ++]);
            }
        } else {
            cout << "NO";
            return ;
        }
    }
    cout << "YES" << endl;
    rep(i, 0, n) {
        if (i) cout << ' ';
        cout << out[i];
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

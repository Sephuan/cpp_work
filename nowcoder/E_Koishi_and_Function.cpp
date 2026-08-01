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
#define rrep(i, a, b) for (auto i = (a); i >= (b); --i)
#define AC return 0;
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

const int MAXN = 10'000'005;
int primes[10'000'010];
bitset<MAXN> st;
int cnt = 0;
int O[10'000'005];

void ola(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primes[++cnt] = i;
            O[i] = 1;
        }
        for (int j = 1; primes[j] <= n / i; ++j) {
            st[primes[j] * i] = true;
            O[primes[j] * i] = O[i] + 1;
            if (i % primes[j] == 0) break;
        }
    }    
}

vector<int> H{1, 1, 2, 3, 5, 7, 11, 13, 17, 19, 
    23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};

void init() {
    ola(MAXN);
}

void solve() {
    int N; MI c; cin >> N >> c;
    MI ans = 0;
    MI t = c;
    rep1(i, 1, N) {
        ans += H[O[i]] * c;
        c *= t;
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

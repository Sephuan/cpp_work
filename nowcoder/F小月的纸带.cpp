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

struct SegTree {
	struct Node {
		array<int, 3> l{}, r{}, cnt{};
		int tag = 0;
	};
	int n; string s; vector<Node> tr;
	explicit SegTree(string& str) : n(str.size()), s(" " + str), tr(4 * n + 5) {
		bd(1, 1, n);
	}
	inline int lc(int u) {
		return u << 1;
	}
	inline int rc(int u) {
		return u << 1 | 1;
	}
	inline void rot(array<int, 3>& x) {
		int tmp = x[2];
		x[2] = x[1];
		x[1] = x[0];
		x[0] = tmp;
	}
	inline void apply(int u, int k) {
		k %= 3;
		rep(i, 0, k) {
			rot(tr[u].l);
			rot(tr[u].r);
			rot(tr[u].cnt);
		}
		tr[u].tag = (tr[u].tag + k) % 3;
	}
	inline void pu(int u) {
		int left = lc(u);
		int right = rc(u);
		rep(c, 0, 3) {
			tr[u].l[c] = tr[left].l[c];
			tr[u].r[c] = tr[right].r[c];
			tr[u].cnt[c] = tr[left].cnt[c] + tr[right].cnt[c] - (tr[left].r[c] && tr[right].l[c]);
		}
	}
	inline void pd(int u) {
		int k = tr[u].tag;
		if (k == 0) {
			return ;
		}
		apply(lc(u), k);
		apply(rc(u), k);
		tr[u].tag = 0;
	}
	void bd(int u, int l, int r) {
		if (l == r) {
			int c = s[l] - 'A';
			tr[u].l[c] = tr[u].r[c] = tr[u].cnt[c] = 1;
			return ;
		}
		int mid = l + r >> 1;
		bd(lc(u), l, mid);
		bd(rc(u), mid + 1, r);
		pu(u);
	}
	void upd(int u, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			apply(u, 1);
			return ;
		}
		pd(u);
		int mid = l + r >> 1;
		if (ql <= mid) {
			upd(lc(u), l, mid, ql, qr);
		}
		if (qr > mid) {
			upd(rc(u), mid + 1, r, ql, qr);
		}
		pu(u);
	}
	void upd(int l, int r) {
		upd(1, 1, n, l, r);
	}
	int qry() {
		return tr[1].cnt[0];
	}
};

void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	SegTree seg(s);
	while (q -- ) {
		int op; cin >> op;
		if (op == 1) {
			int l, r; cin >> l >> r;
			seg.upd(l, r);
		} else {
			cout << seg.qry() << endl;
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    Sephuan
}

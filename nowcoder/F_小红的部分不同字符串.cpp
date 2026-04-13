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
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

ll qpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

void solve1() {
    int n;
    cin >> n;
    vector<int> a(n + 1), in(n + 1, 0);
    rep1(i, 1, n) {
        cin >> a[i];
        in[a[i]] ++;
    }
    queue<int> que;
    rep1(i, 1, n) {
        if (in[i] == 0)
            que.push(i);
    }
    int ind0 = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        ind0 ++;
        int v = a[u];
        if (--in[v] == 0) que.push(v);
    }
    ll ans = qpow(25, ind0);
    rep1(i, 1, n) {
        if (in[i]) {
            int len = 0;
            int cur = i;
            while (in[cur]) {
                in[cur] = 0;
                cur = a[cur];
                len ++;
            }
            ans = ans * (qpow(25, len) + (len % 2 == 1 ? MOD - 25 : 25)) % MOD;
        }
    }
    cout << ans;
}

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int u) {
        if (u == fa[u]) return u;
        return fa[u] = find(fa[u]);
    }
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) fa[pu] = pv;
    }
};

void solve2() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    DSU dsu(n);
    ll ans = 1;
    int nodes = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (dsu.find(i) == dsu.find(a[i])) {
            int len = 1;
            int cur = a[i];
            while (cur != i) {
                cur = a[cur];
                len++;
            }
            nodes -= len;
            ans = ans * (qpow(25, len) + (len % 2 == 1 ? MOD - 25 : 25)) % MOD;
        } else dsu.unite(i, a[i]);
    }
    ans = ans * qpow(25, nodes) % MOD;
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
        solve2();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

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
#define AC return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 1'000'005;

void init() {

}

struct e {
    int v, id;
};

ll qpow(ll a, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1) r = r * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return r;
}

void solve() {
    int N, M; cin >> N >> M;
    vector G(N + 1, vector<e>());
    vector<pii> E(1);
    rep1(i, 1, M) {
        int u, v; cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
        E.push_back({u, v});
    }
    auto chk = [&](int mid) -> bool {
        int s = 1;
        vector<int> seen(N + 1);
        auto dfs = [&](auto&& self, int s) -> void {
            seen[s] = 1;
            for (auto [v, id] : G[s]) {
                if (id > mid && !seen[v]) {
                    self(self, v);
                    seen[v] = 1;
                }
            }
        };
        dfs(dfs, 1);
        int f = 0;
        rep1(i, 2, N) if ((seen[i] ^ seen[i - 1])) {f = 1; break;}
        return f;
    };
    int l = 1, r = M;
    int minm = M;
    while (l <= r) {
        int mid = l + (r - l >> 1);
        if (chk(mid)) {
            minm = min(minm, mid);
            r = mid - 1;
        } else l = mid + 1;
    }
    vector<int> seen(N + 1);
    auto dfs = [&](auto&& self, int s, int m) -> void {
        seen[s] = 1;
        for (auto [v, id] : G[s]) {
            if (id > m && !seen[v]) {
                self(self, v, m);
                seen[v] = 1;
            }
        }
    };
    dfs(dfs, 1, minm);
    ll ans = 0;
    rep1(i, 1, M) {
        if (seen[E[i].fi] ^ seen[E[i].se])
            ans += qpow(2, i);
        ans %= MOD;
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

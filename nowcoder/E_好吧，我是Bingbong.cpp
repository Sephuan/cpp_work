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
const int MAXN = 2'00'005;

void init() {

}

struct node {
    int id;
    ll w;
};


void solve() {
    int n; cin >> n;
    vector<ll> h(n + 1), S(n + 1), ans(n + 1);
    vector<vector<node>> adj(n + 1);

    auto dfs1 = [&](auto& dfs, int u) -> void{
        S[u] = h[u];
        for (auto& v : adj[u]) {
            dfs(dfs, v.id);
            S[u] += S[v.id];
        }
    };

    auto dfs2 = [&](auto& dfs, int u) -> void {
        sort(adj[u].begin(), adj[u].end(), [](auto& a, auto& b) {
            return a.w > b.w;
        });
        ll sum_higher = 0;
        for (auto& v : adj[u]) {
            ans[v.id] = ans[u] - (h[u] - v.w) - sum_higher;
            sum_higher += S[v.id];
            dfs(dfs, v.id);
        }
    };

    rep1(i, 1, n) cin >> h[i];
    vector<int> f(n + 1);
    rep1(i, 2, n) cin >> f[i];
    rep1(i, 2, n) {
        ll w; cin >> w;
        adj[f[i]].push_back({i, w});
    }

    dfs1(dfs1, 1);
    ans[1] = S[1];
    dfs2(dfs2, 1);
    rep1(i, 1, n) {
        cout << ans[i] << " \n"[i == n];
    }
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

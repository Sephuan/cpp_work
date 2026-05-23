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
const int MAXN = 1'005;

void init() {

}

int n;
vector<int> adj[MAXN];
int dp[MAXN][MAXN];
int sz[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    dp[u][1] = 0;
    for (int& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        vector<int> tmp(sz[u] + sz[v] + 1, INF);
        rep1(j, 1, sz[u]) {
            if (dp[u][j] == INF) continue;
            tmp[j] = min(tmp[j], dp[u][j] + 1);
            rep1(k, 1, sz[v]) {
                if (dp[v][k] == INF) continue;
                tmp[j + k] = min(tmp[j + k], dp[u][j] + dp[v][k]);
            }
        }
        sz[u] += sz[v];
        rep1(j, 1, sz[u]) dp[u][j] = tmp[j];
    }
}

void solve() {
    cin >> n;
    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, 0x3f, sizeof dp);
    dfs(1, 0);
    rep1(i, 1, n) {
        cout << dp[1][i] << " \n"[i == n];
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

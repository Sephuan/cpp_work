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

void solve() {
    int N; cin >> N;
    vector adj(N + 1, vector<int>());
    vector d(N + 1, 0);
    rep(i, 1, N) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        d[a] ++;
        d[b] ++;
    }
    vector<int> order{0}, parent(N + 1);
    order.push_back(1);
    rep1(i, 1, N) {
        int u = order[i];
        for (auto v : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            order.push_back(v);
        }
    }
    vector<int> dp(N + 1, 0);
    int ans = 1;
    rrep(i, N, 1) {
        int u = order[i];
        if (d[u] <= 2) continue;
        int best1 = 0, best2 = 0;
        for (auto v : adj[u]) {
            if (v == parent[u]) continue;
            if (dp[v] > best1) {
                best2 = best1;
                best1 = dp[v];
            } else if (dp[v] > best2) {
                best2 = dp[v];
            }
        }
        if (d[u] == 3) {
            dp[u] = 1;
            ans = max(ans, 1 + best1);
        } else if (d[u] > 3) {
            dp[u] = 1 + best1;
            ans = max(ans, 1 + best1 + best2);
        }
    }
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
    AC
}

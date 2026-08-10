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
const int MAXN = 10'000'005;

void init() {

}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector adj(n + 1, vector<int>());
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int src) -> pair<int, vector<int>> {
        vector<int> dist(n + 1, -1);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int far = src;
        rep1(i, 1, n) {
            if (s[i] == '1' && dist[i] > dist[far]) {
                far = i;
            }
        }
        return {far, dist};
    };
    int r = 1;
    while (s[r] != '1') r ++;
    auto [A, tmp] = bfs(r);
    auto [B, distA] = bfs(A);
    int diam = distA[B];
    auto [t, distB] = bfs(B);
    rep1(i, 1, n) {
        cout << max({diam, distA[i], distB[i]}) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    //cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    Sephuan
}

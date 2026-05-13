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
const int MAXN = 1'00'005;

void init() {

}

void solve() {
    int N, M; cin >> N >> M;
    vector<int> adj[N + 1];
    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int W; cin >> W;
    vector mark(N + 1, vector<bool>(W));
    vector out(N + 1, vector<int>(W));
    vector<string> S(N + 1);
    queue<pii> q;
    rep1(i, 1, N) cin >> S[i];
    rep1(u, 1, N) rep(j, 0, W) {
        if (S[u][j] == 'x') {
            mark[u][j] = 1;
        } else {
            int nxt = (j + 1) % W;
            if (S[u][nxt] == 'o') out[u][j] ++;
            for (int& v : adj[u]) {
                if (S[v][nxt] == 'o') out[u][j] ++;
            }
            if (out[u][j] == 0) {
                q.push({u, j});
                mark[u][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        auto& [v, nxt_j] = q.front();
        q.pop();
        int j = (nxt_j - 1 + W) % W;
        vector<int> pro = adj[v];
        pro.push_back(v);
        for (int& u : pro) {
            if (!mark[u][j]) {
                out[u][j] --;
                if (out[u][j] == 0) {
                    mark[u][j] = 1;
                    q.push({u, j});
                }
            }
        }
    }
    rep1(i, 1, N) {
        if (out[i][0]) {
            cout << "Yes";
            return ;
        }
    }
    cout << "No";
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

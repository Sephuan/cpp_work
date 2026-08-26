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
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 205;

void init() {

}

int n, m, A, B, T;
vector<int> adj[MAXN];
bool g[MAXN][MAXN];
int res[MAXN][MAXN][2];
int cnt[MAXN][MAXN][2];
queue<array<int, 3>> q;
const int DRAW = 0, WIN_W = 1, WIN_Z = 2;

inline void settle(int a, int b, int t, int v) {
    res[a][b][t] = v;
    q.push({a, b, t});
}

void solve() {
    cin >> n >> m >> A >> B >> T;
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        g[u][v] = g[v][u] = true;
    }
    rep1(a, 1, n) {
        if (a == T) continue;
        rep1(b, 1, n) {
            if (b == a) continue;
            if  (g[a][T] && T != b) {
                settle(a, b, 0, WIN_W);
            } else {
                int c = adj[a].size();
                if (g[a][b]) c --;
                cnt[a][b][0] = c;
                if (c == 0) settle(a, b, 0, WIN_Z);
            }
            if (g[a][b]) {
                settle(a, b, 1, WIN_Z);
            } else {
                cnt[a][b][1] = adj[b].size();
            }
        }
    }
    while (!q.empty()) {
        auto [a, b, t] = q.front();
        q.pop();
        int v = res[a][b][t];
        if (t == 1) {
            for (int pa : adj[a]) {
                if (pa == b || pa == T) continue;
                if (res[pa][b][0] != DRAW) continue;
                if (v == WIN_W) 
                    settle(pa, b, 0, WIN_W);
                else if (-- cnt[pa][b][0] == 0)
                    settle(pa, b, 0, WIN_Z);
            }
        } else {
            for (int pb : adj[b]) {
                if (pb == a) continue;
                if (res[a][pb][1] != DRAW) continue;
                if (v == WIN_Z)
                    settle(a, pb, 1, WIN_Z);
                else if (-- cnt[a][pb][1] == 0) {
                    settle(a, pb, 1, WIN_W);
                }
            }
        }
    }
    int ans = res[A][B][0];
    cout << (ans == WIN_W ? "WSQ" : ans ? "ZZ" : "DRAW");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int Tt = 1;
    // cin >> T;
    cout << fixed << setprecision(15);
    while (Tt--) {
        solve();
        if (Tt) {
            cout << '\n';
        }
    }
    Sephuan
}

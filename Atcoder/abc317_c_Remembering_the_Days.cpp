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

void solve() {
    int N, M; cin >> N >> M;
    int g[11][11];
    set<int> s;
    memset(g, 0, sizeof g);
    rep1(i, 1, M) {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    int ans = 0;
    auto dfs = [&](auto& self, int idx, int cur) -> void {
        ans = max(ans, cur);
        rep1(j, 1, N) {
            if (g[idx][j] && !s.count(j)) {
                s.insert(j);
                self(self, j, cur + g[idx][j]);
                s.erase(j);
            }
        }
    };
    rep1(i, 1, N) {
        s.clear();
        s.insert(i);
        dfs(dfs, i, 0);
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

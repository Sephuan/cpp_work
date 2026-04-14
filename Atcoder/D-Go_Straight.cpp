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
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

char g[1'005][1'005];
int H, W;
bool vis[1'005][1'005][4];

void solve() {
    cin >> H >> W;
    int sx, sy;
    rep1(i, 1, H) rep1(j, 1, W) {
        cin >> g[i][j];
        if (g[i][j] == 'S')
            sx = i, sy = j;
    }
    vector<char> path;
    int f = 0;
    auto dfs = [&](auto& self, int x, int y, int ld) -> void {
        if (f) return;
        if (vis[x][y][ld]) return;
        vis[x][y][ld] = 1;
        char c = g[x][y];
        if (c == 'G') {
            f = 1;
            cout << "Yes" << endl;
            for (char& c : path)
                cout << c;
        }
        rep(i, 0, 4) {
            if (c == 'o' && i != ld) continue;
            if (c == 'x' && i == ld) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx && ny && nx <= H && ny <= W && g[nx][ny] != '#') {
                path.push_back(dc[i]);
                self(self, nx, ny, i);
                path.pop_back();
            }
        }
    };
    dfs(dfs, sx, sy, 0);
    if (!f) cout << "No";
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

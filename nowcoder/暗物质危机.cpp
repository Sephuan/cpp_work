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
const int MAXN = 3'00'005;

void init() {

}

char g[1'005][1'005];
int m[1'005][1'005];
void solve() {
    int N, M; cin >> N >> M;
    memset(m, 0x3f, sizeof m);
    int SX, SY, EX, EY;
    queue<pair<pii, int>> pts;
    rep1(i, 1, N) rep1(j, 1, M) {
        cin >> g[i][j];
        if (g[i][j] == 'A') {SX = i; SY = j;}
        else if (g[i][j] == 'E') {EX = i; EY = j;}
        else if (g[i][j] == '*') {
            m[i][j] = 0;
            pts.push({{i, j}, 0});
        }
    }
    while (!pts.empty()) {
        auto [p, tim] = pts.front(); pts.pop();
        auto [x, y] = p;
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > M 
                || g[nx][ny] == '#'
                || m[nx][ny] != INF) continue;
            else {
                m[nx][ny] = tim + 1;
                pts.push({{nx, ny}, tim + 1});
            }
        }
    }
    pts.push({{SX, SY}, 0});
    while (!pts.empty()) {
        auto [p, tim] = pts.front(); pts.pop();
        auto [x, y] = p;
        if (g[x][y] == 'E') {
            cout << tim;
            return ;
        }
        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > M 
                || g[nx][ny] == '#'
                || m[nx][ny] <= tim + 1) continue;
            m[nx][ny] = -1;
            pts.push({{nx, ny}, tim + 1});
        }
    }
    cout << -1;
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

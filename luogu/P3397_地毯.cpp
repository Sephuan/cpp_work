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
    int n, m; cin >> n >> m;
    vector d(1'005, vector(1'005, 0));
    vector a = d;
    rep1(i, 1, m) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1] += 1;
        d[x1][y2 + 1] -= 1;
        d[x2 + 1][y1] -= 1;
        d[x2 + 1][y2 + 1] += 1;
    }
    rep1(i, 1, n) rep1(j, 1, n) {
        a[i][j] = a[i - 1][j] + a[i][j - 1] + d[i][j] - a[i - 1][j - 1];
        cout << a[i][j] << " \n"[j == n];
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

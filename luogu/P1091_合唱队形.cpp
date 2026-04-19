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

void solve() {
    int n;
    cin >> n;
    vector<int> t(n + 1, 0), f(n + 1, 1), g(n + 2, 1);
    f[0] = g[0] = g[n + 1] = 0;
    rep1(i, 1, n) cin >> t[i];
    rep1(i, 1, n) {
        rep(j, 1, i) {
            if (t[j] < t[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    rrep(i, n, 1) {
        rrep(j, n, i + 1) {
            if (t[i] > t[j]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }
    int ans = n;
    rep1(i, 0, n) {
        ans = min(ans, n - f[i] - g[i] + 1);
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

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
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3fLL;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int c0 = 0, c1 = 0;
    rep(i, 0, n) if (s[i] ^ 48) c1 ++; else c0 ++;
    char fir = s[0];
    char t = fir; int r = 1;
    int dc = c1 - c0;
    rep(i, 1, n) if (s[i] != t) {
        t = s[i];
        r ++;
    }
    int mk = -1;
    /*
    d1 = c1 - k1
    d0 = c0 - k0
    |d1 - d0| = |c1 - c0 - (k1 - k0)| <= 1
    */
    rep1(k, -1, 1) {
        if (abs(dc - k) > 1) continue;
        if (fir == '0') {
            if (k == -1) {
                mk = max(mk, (r & 1) ? r : r - 1);
            } else if (k == 0) {
                mk = max(mk, (r & 1) ? r - 1 : r);
            } else {
                mk = max(mk, (r & 1) ? r - 2 : r - 1);
            }
        } else {
            if (k == -1) {
                mk = max(mk, (r & 1) ? r - 2 : r - 1);
            } else if (k == 0) {
                mk = max(mk, (r & 1) ? r - 1 : r);
            } else {
                mk = max(mk, (r & 1) ? r : r - 1);
            }
        }
    }
    if (mk == -1) cout << -1;
    else cout << n - mk;
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

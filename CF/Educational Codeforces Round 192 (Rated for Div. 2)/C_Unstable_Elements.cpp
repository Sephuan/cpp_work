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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int lst = 0;
    int cdf = 0;
    vector<int> f;
    rep(i, 0, n) {
        if (a[i] != lst) {
            lst = a[i];
            f.push_back(1);
            cdf ++;
        } else (*f.rbegin()) ++;
    }
    ranges::sort(f);
    lst = 0;
    int ans = 0;
    int tof = accumulate(f.begin(), f.end(), 0);
    rep(i, 0, cdf) {
        if (f[i] == lst) { tof -= f[i]; continue; }
        int rd = cdf - i;
        int rt = tof - rd * (f[i] - 1);
        if (k >= rt && (k - rt) % rd == 0) ans ++;
        lst = f[i];
        tof -= lst;
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

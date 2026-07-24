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
const int MAXN = 1'000'005;

void init() {

}

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(3 * n);
    rep(i, 0, n) cin >> a[i];
    rep(i, n, 2 * n) a[i] = a[i - n];
    rep(i, 2 * n, 3 * n) a[i] = a[i - n];
    vector<ll> pre(3 * n);
    pre[0] = a[0];
    rep(i, 1, 3 * n) pre[i] = pre[i - 1] + a[i];
    ll ans = 0;
    rep(i, n, 2 * n) {
        ll dsum = pre[i + d] - (i - d - 1 > 0 ? pre[i - d - 1] : 0) - a[i];
        ll con = 2LL * d * a[i] - dsum;
        if (con > 0) ans += con;
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

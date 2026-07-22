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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    rep1(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<ll> P(n + 1);
    rep1(i, 1, n) P[i] = P[i - 1] + a[i];
    ll ans = LLONG_MIN;
    if (k & 1) {
        int m = k >> 1;
        int L = m + 1;
        int R = n - m;
        rep1(i, L, R) {
            ans = max(ans, 2 * m * a[i] - P[m] - (P[i + m] - P[i]));
        }
    } else {
        int m = k - 2 >> 1;
        int L = m + 1;
        int R = n - m - 1;
        rep1(i, L, R) {
            ans = max(ans, m * (a[i] + a[i + 1]) - P[m] - (P[i + 1 + m] - P[i + 1]));
        }
    }
    cout << ans + P[n];
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

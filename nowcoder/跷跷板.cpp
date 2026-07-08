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
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

typedef __int128_t lll;

void init() {

}

void solve() {
    int n; cin >> n;
    ll l, W; cin >> l >> W;
    lll Sx = 0;
    ll Sw = 0;
    vector<ll> x(n), w(n);
    rep(i, 0, n) {
        cin >> x[i] >> w[i];
        Sx += (lll)x[i] * w[i];
        Sw += w[i];
    }
    int ans = 0;
    rep(i, 0, n) {
        lll N = 2 * (Sx - (lll)x[i] * w[i]) + (lll)W * l;
        lll D = 2 * ((lll)Sw - w[i] + W);
        if (N % D == 0) {
            lll p = N / D;
            if (p <= l) ans ++;
        }
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

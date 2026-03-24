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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n;
    cin >> n;
    vector a(n, 0);
    rep(i, 0, n) cin >> a[i];
    if (n == 1) {cout << -1; return;}
    sort(a.begin(), a.end());
    int M = a[n - 1 >> 1];
    int L = lower_bound(a.begin(), a.end(), M) - a.begin();
    int R = upper_bound(a.begin(), a.end(), M) - a.begin() - 1;
    int ans = 1e9;
    if (L > 0) ans = min(ans, n - 2 * L);
    if (R < n - 1) ans = min(ans, 2 * R + 3 - n);
    if (ans == 1e9) cout << -1;
    else cout << ans;
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

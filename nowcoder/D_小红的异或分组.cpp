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
    vector<ll> a(n), p(n + 1, 0);
    ll zero = -1;
    rep(i, 0, n) {
        cin >> a[i];
        p[i + 1] = p[i] ^ a[i];
        if (p[i + 1] == 0) zero ++;
    }
    if (p[n] == 0) {
        cout << (zero * (zero - 1) >> 1);
    } else {
        ll ans = 0, cnt = 0;
        rep(i, 1, n) {
            if (p[i] == p[n]) cnt ++;
            if (p[i] == 0) ans += cnt;
        }
        cout << ans;
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

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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

int L(ll n) {
    if (n == 0) return 1;
    int r = 0;
    while (n) {
        n /= 10;
        r ++;
    }
    return r;
}

ll pow_10(int p) {
    ll r = 1;
    while (p --) {
        r *= 10;
    }
    return r;
}

void solve() {
    ll C, D;
    cin >> C >> D;
    int min_L = L(C + 1);
    ll ans = 0;
    rep1(len, min_L, 10) {
        ll min_y = max((ll)pow_10(len - 1), C + 1);
        ll max_y = min((ll)pow_10(len) - 1, C + D);
        ll l = pow_10(len) * C + min_y;
        ll r = pow_10(len) * C + max_y;
        if (min_y <= max_y)
            ans += floor(sqrtl(r)) - ceil(sqrtl(l)) + 1;
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

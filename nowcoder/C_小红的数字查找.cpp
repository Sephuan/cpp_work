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

const int MAXN = 2'00'005;

void init() {

}

void solve() {
    ll x, l, r;
    cin >> x >> l >> r;
    for (int i = 2, t; (t = i * i) <= x; ++i) {
        if (x % t == 0) {
            x /= t;
        }
    }
    ll k_2 = (l + x - 1) / x;
    ll k = sqrt(k_2);
    if (k * k < k_2) k++;
    ll y = x * k * k;
    if (y > r) cout << -1;
    else cout << y;
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

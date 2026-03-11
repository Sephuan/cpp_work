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
    int m, c, q;
    cin >> m >> c >> q;
    vector a(m, 0);
    rep(i, 0, m) cin >> a[i];
    while (q--) {
        ll x;
        cin >> x;
        bool f = 0, skip = 0;
        vector mark(m, -1LL);

        while (x <= c) {
            if (x == c) {
                f = 1;
                break;
            }
            int r = x % m;
            if (a[r] == 0) break;
            if (!skip && mark[r] != -1) {
                ll diff = x - mark[r];
                ll cnt = (c - x) / diff;
                if (cnt) x = x + cnt * diff;
                skip = 1;
                continue;
            }
            if (!skip) mark[r] = x;
            x = x + a[r];
        }
        if (f) cout << "Yes";
        else cout << "No";
        if (q) cout << '\n';
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

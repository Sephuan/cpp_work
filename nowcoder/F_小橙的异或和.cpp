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
    int n, q;
    cin >> n >> q;
    vector a(n + 1, 0);
    set<int> s;
    ll xsum = 0;
    rep1(i, 1, n) {
        cin >> a[i];
        s.insert(i);
        xsum ^= a[i];
    }
    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            int l, r;
            cin >> l >> r;
            for (auto it = s.lower_bound(l); it != s.upper_bound(r); ) {
                xsum ^= a[*it];
                a[*it] /= (*it - l + 1);
                xsum ^= a[*it];
                if (a[*it] == 0) it = s.erase(it);
                else ++it;
            }
        } else {
            cout << xsum;
            if (q) cout << '\n';
        }
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

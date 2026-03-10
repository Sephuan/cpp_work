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
    int n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    string ans = "";
    int dx = abs(x1 - x2);
    if (dx <= 1) cout << -1;
    else {
        if ((x1 == x2 && (dx & 1)) || (x1 != x2 && (dx % 2 == 0))) {
            cout << -1;
            return ;
        }
        if (y1 < y2 && x1 == x2) {
            ans += string(x1 - 1, 'L');
            if (x1 == 1) {
                ans += 'D';
                ans += string(x1 - 1, 'R');
                rep(i, 0, x2 - x1 >> 1) ans += "RURD";
                ans += string(n - y2 + 1, 'R');
                ans += 'U';
                ans += string(n - y2, 'L');
            } else {
                ans += 'U';
                ans += string(x1 - 1, 'R');
                rep(i, 0, x2 - x1 >> 1) ans += "RDRU";
                ans += string(n - y2 + 1, 'R');
                ans += 'D';
                ans += string(n - y2, 'L');
            }
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

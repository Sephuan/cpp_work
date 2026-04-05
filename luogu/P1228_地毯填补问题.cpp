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

void d(int x, int y, int hx, int hy, int len) {
    if (len == 1) return ;
    int h = len >> 1;
    int px = x + h, py = y + h;
    if (hx < px && hy < py) {
        cout << px << ' ' << py << ' ' << 1 << endl;
        d(x, y, hx, hy, h);
        d(x, py, px - 1, py, h);
        d(px, y, px, py - 1, h);
        d(px, py, px, py, h);
    } else if (hx < px) {
        cout << px << ' ' << py - 1 << ' ' << 2 << endl;
        d(x, y, px - 1, py - 1, h);
        d(x, py, hx, hy, h);
        d(px, y, px, py - 1, h);
        d(px, py, px, py, h);
    } else if (hy < py) {
        cout << px - 1 << ' ' << py << ' ' << 3 << endl;
        d(x, y, px - 1, py - 1, h);
        d(x, py, px - 1, py, h);
        d(px, y, hx, hy, h);
        d(px, py, px, py, h);
    } else {
        cout << px - 1 << ' ' << py - 1 << ' ' << 4 << endl;
        d(x, y, px - 1, py - 1, h);
        d(x, py, px - 1, py, h);
        d(px, y, px, py - 1, h);
        d(px, py, hx, hy, h);
    }
}

void solve() {
    int k;
    cin >> k;
    int hx, hy;
    cin >> hx >> hy;
    d(1, 1, hx, hy, 1 << k);
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

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
    ll Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;
    // 2 * [ (x2 - x1) * x + (y2 - y1) * y ] = x2*x2 +y2*y2 - x1*x1 - y1*y1
    // a = 2 * (x2 - x1), b = 2 * (y2 - y1)
    // c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1
    // a1 * x1 + b1 * y1 = c1
    // a2 * x2 + b2 * y2 = c2
    // D = a1 * b2 - b1 * a2
    ll a1 = 2LL * (Qx - Px), b1 = 2LL * (Qy - Py);
    ll c1 = Qx * Qx + Qy * Qy - Px * Px - Py * Py;
    ll a2 = 2LL * (Sx - Rx), b2 = 2LL * (Sy - Ry);
    ll c2 = Sx * Sx + Sy * Sy - Rx * Rx - Ry * Ry;
    ll D = a1 * b2 - b1 * a2;
    if (D == 0 && ((Px + Qx) * a2 + (Py + Qy) * b2 != c2 * 2)) {
        cout << "No";
        return ;
    } 
    cout << "Yes";
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

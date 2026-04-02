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
/*
M - m - r + l

(M - m) - (r - l)
    
y >= x;
|ax - ay| - (y - x);

case 1 -> ax >= ay:
    (ax + x) - (ay + y)
        
case 2 -> ax < ay:
    (ay - y) - (ax - x)
*/
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep1(i, 1, n) cin >> a[i];
    int Mx = 0, mx = 1e9;
    int ans = 0;
    rep1(i, 1, n) {
        Mx = max(Mx, a[i] + i);
        mx = min(mx, a[i] - i);
        ans = max(ans, max(Mx - (a[i] + i), (a[i] - i) - mx));
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

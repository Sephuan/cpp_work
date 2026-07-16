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
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    ll A, B, X, Y; cin >> A >> B >> X >> Y;
    X = abs(X), Y = abs(Y);
    auto ec = [&](ll x, ll y) {
        ll s = 0;
        s += min(x, y) * (min(A, B) << 1);
        s += (max(x, y) - min(x, y) >> 1) * min(A + B, min(A, B) << 2);
        return s;
    };
    ll ans = 0;
    if (X + Y & 1) {
        ans = min(
            A + min(ec(X - 1, Y), ec(X + 1, Y)),
            B + min(ec(X, Y - 1), ec(X, Y + 1))
        );
    } else ans = ec(X, Y);
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

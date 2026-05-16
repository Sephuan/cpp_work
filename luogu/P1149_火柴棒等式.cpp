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
    int n; int A, B, C;
    int ans = 0;
    int ca, cb, cc;
    int mp[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    cin >> n;
    rep1(a1, 0, 9) rep1(a2, 0, 9) rep1(a3, 0, 9)
    rep1(b1, 0, 9) rep1(b2, 0, 9) rep1(b3, 0, 9) {
        if (a1 == 0) {
            if (a2 == 0) ca = mp[a3];
            else ca = mp[a2] + mp[a3];
        } else ca = mp[a1] + mp[a2] + mp[a3];
        A = a1 * 100 + a2 * 10 + a3;
        if (b1 == 0) {
            if (b2 == 0) cb = mp[b3];
            else cb = mp[b2] + mp[b3];
        } else cb = mp[b1] + mp[b2] + mp[b3];
        B = b1 * 100 + b2 * 10 + b3;
        C = A + B;
        cc = (C == 0 ? 6 : 0);
        while (C) {
            cc += mp[C % 10];
            C /= 10;
        }
        if (ca + cb + cc + 4 == n) ans ++;
    }
    cout << ans;
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

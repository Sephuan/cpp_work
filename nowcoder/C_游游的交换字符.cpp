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
#define int long long
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
    string s; cin >> s;
    int n = s.size();
    int c0 = 0, c1 = 0;
    for (auto& c : s) {
        if (c == '1') c1 ++;
        else c0 ++;
    }
    int ans = 0;
    if (c1 > c0) {
        int f = 0;
        rep(i, 0, n) {
            if (s[i] == '1') {
                ans += abs(i - f);
                f += 2;
            }
        }
    } else if (c1 < c0) {
        int f = 0;
        rep(i, 0, n) {
            if (s[i] == '0') {
                ans += abs(i - f);
                f += 2;
            }
        }
    } else {
        int r1 = 0, r2 = 0;
        int f = 0, g = 0;
        rep(i, 0, n) {
            if (s[i] == '1') {
                r1 += abs(i - f);
                f += 2;
            }
            if (s[i] == '0') {
                r2 += abs(i - g);
                g += 2;
            }
        }
        ans = min(r1, r2);
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

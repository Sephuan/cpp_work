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

void solve() {
    string S, T;
    cin >> S >> T;
    int n = S.length();
    vector<vector<int>> nxt(n + 1, vector (26, n));
    rrep(i, n - 1, 0) {
        rep(j, 0, 26) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][S[i] - 'a'] = i;
    }
    ll ans = 0;
    rep(L, 0, n) {
        int f = 1;
        int cur = L;
        for (char& c : T) {
            cur = nxt[cur][c - 'a'];
            if (cur == n) {
                f = 0;
                break;
            }
            cur ++;
        }
        if (f) ans += cur - 1 - L;
        else ans += n - L;
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

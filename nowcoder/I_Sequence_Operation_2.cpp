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
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int pos = 0;
    rep(i, 1, 1 << n) {
        if (s[i] == '1') {
            pos ^= i;
        }
    }
    string d = string(1 << n, '0');
    rep(i, 1, 1 << n) {
        if (i == pos) {
            if (s[i] != '1') d[i] = '1';
        } else if (s[i] == '1') d[i] = '1';
    }
    vector<int> ans(1 << n);
    rrep(i, (1 << n) - 1, 1) {
        if ((d[i] == '1') && __builtin_popcount(i) != 1) {
            int hi = 31 - __builtin_clz(i);
            int p = 1 << hi;
            int r = i ^ p;
            ans[i] = p;
            d[p] ^= 1;
            d[r] ^= 1;
        }
    }
    rep(i, 1, 1 << n) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }
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

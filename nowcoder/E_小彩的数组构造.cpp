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
    int a, b, c; cin >> a >> b >> c;
    if (a < max(b, c)) {
        cout << -1; return ;
    }
    int X = min(b, c);
    int Y = b - X;
    int Z = c - X;
    int W = a - max(b, c);
    int lenB = X + 2;
    int lenC = Y, lenD = Z;

    cout << a + 2 << endl;
    if (W == 1) cout << 7 << ' ';
    else if (W >= 2) {
        vector<int> base;
        if (W % 3 == 0) base = {6, 4, 7};
        else if (W % 3 == 1) base = {7, 6, 4};
        else base = {4, 7, 6};
        rep(i, 0, W) cout << base[i % 3] << ' ';
    }
    rep(i, 0, lenB) cout << 6 << ' ';
    rep1(i, 1, lenC) {
        if (i % 2) cout << 2 << ' ';
        else cout << 6 << ' ';
    }
    rep(i, 0, lenD) {
        if (i % 3 == 0) cout << 3 << ' ';
        else cout << 6 << ' ';
    }
    cout << endl;
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

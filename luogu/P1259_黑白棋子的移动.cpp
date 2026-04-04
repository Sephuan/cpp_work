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
    int n;
    cin >> n;

    int tn = n;
    cout << string(n, 'o') << string(n, '*') << "--" << endl;
    while (tn-- > 4) {
        cout << string(tn, 'o') << "--" << string(tn, '*');
        rep1(i, 1, n - tn) cout << "o*";
        cout << endl << string(tn, 'o') << string(tn, '*') << "--";
        rep1(i, 1, n - tn) cout << "o*";
        cout << endl;
    }
    tn = n - tn;
    cout << "ooo--***o*";
    rep(i, 1, tn) cout << "o*";
    cout << endl << "ooo*o**--*";
    rep(i, 1, tn) cout << "o*";
    cout << endl << "o--*o**oo*";
    rep(i, 1, tn) cout << "o*";
    cout << endl << "o*o*o*--o*";
    rep(i, 1, tn) cout << "o*";
    cout << endl << "--o*o*o*o*";
    rep(i, 1, tn) cout << "o*";
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

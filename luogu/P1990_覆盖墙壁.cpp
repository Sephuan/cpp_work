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
    f[i]        =  f[i - 1] + f[i - 2] + 2f[i - 3] + 2f[i - 4] + ...
    f[i - 1]    =             f[i - 2] + f[i - 3]  + 2f[i - 4] + ...
    f[i] =  2f[i - 1] + f[i - 3]
*/
void solve() {
    int N;
    cin >> N;
    int f1 = 1, f2 = 2, f3 = 5, f;
    if (N == 1) cout << 1;
    else if (N == 2) cout << 2;
    else if (N == 3) cout << 5;
    else rep1(i, 4, N) {
        (f = 2 * f3 + f1) %= 10'000;
        f1 = f2;
        f2 = f3;
        f3 = f;
    }
    cout << f;
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

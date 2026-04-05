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

string dfs(int x) {
    if (x == 0) return "0";
    if (x == 1) return "2(0)";
    if (x == 2) return "2";
    string res = "";
    int l = 1, p = 0;
    while ((l << 1) <= x) l <<= 1, p++;
    int r = x - l;
    if (p == 1) res += "2";
    else res += "2(" + dfs(p) + ")";
    if (r) res += '+' + dfs(r);
    return res;
}

void solve() {
    int n;
    cin >> n;
    cout << dfs(n);
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

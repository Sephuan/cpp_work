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
    int Q;
    cin >> Q;
    vector<int> cnt_l(Q + 1), cnt_r(Q + 1);
    int p = 0;
    while (Q --) {
        int op;
        cin >> op;
        if (op == 1) {
            p ++;
            char c;
            cin >> c;
            if (c == '(') {
                cnt_l[p] = cnt_l[p - 1];
                cnt_r[p] = cnt_r[p - 1] + 1;
            } else if (cnt_r[p - 1] > 0) {
                cnt_r[p] = cnt_r[p - 1] - 1;
                cnt_l[p] = cnt_l[p - 1];
            } else {
                cnt_r[p] = cnt_r[p - 1];
                cnt_l[p] = cnt_l[p - 1] + 1;
            }
        } else {
            p --;
        }
        cout << (cnt_l[p] == 0 && cnt_r[p] == 0 ? "Yes" : "No") << '\n';
    }
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

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
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    string ans;
    int dy = abs(y1 - y2);
    if (dy <= 1) {
        if (y1 == y2) {
            if (y1 == 1) {
                ans += string(n - 1, 'R');
                ans += (x1 == 1 ? 'D' : 'U');
                ans += string(n - 1, 'L');
                cout << ans;
            } else if (y1 == n) {
                ans += string(n - 1, 'L');
                ans += (x1 == 1 ? 'D' : 'U');
                ans += string(n - 1, 'R');
                cout << ans;
            } else cout << -1;
        } else {
            if (n == 2 && x1 == x2) {
                if (x1 == 1) {
                    if (y1 < y2) cout << "DRU";
                    else cout << "DLU";
                } else {
                    if (y1 < y2) cout << "URD";
                    else cout << "ULD";
                }
            } else cout << -1;
        }
    }
    else {
        if ((x1 == x2 && (dy % 2 == 0)) || (x1 != x2 && (dy & 1))) {
            cout << -1;
            return ;
        }
        if (y1 < y2) {
            ans += string(y1 - 1, 'L');
            if (x1 == x2) {
                if (x1 == 1) {
                    ans += 'D';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RURD";
                    ans += string(n - y2 + 1, 'R');
                    ans += 'U';
                    ans += string(n - y2, 'L');
                } else {
                    ans += 'U';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RDRU";
                    ans += string(n - y2 + 1, 'R');
                    ans += 'D';
                    ans += string(n - y2, 'L');
                }
            } else {
                if (x1 == 1) {
                    ans += 'D';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RURD";
                    if (y2 != n) {
                        ans.pop_back();
                        ans += string(n - y2, 'R');
                        ans += 'D';
                        ans += string(n - y2, 'L');
                    }
                } else {
                    ans += 'U';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RDRU";
                    if (y2 != n) {
                        ans.pop_back();
                        ans += string(n - y2, 'R');
                        ans += 'U';
                        ans += string(n - y2, 'L');
                    }
                }
            }
            cout << ans;
        } else {
            swap(x1, x2);
            swap(y1, y2);

            if (x1 == x2) {
                ans += string(y1 - 1, 'L');
                if (x1 == 1) {
                    ans += 'D';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RURD";
                    ans += string(n - y2 + 1, 'R');
                    ans += 'U';
                    ans += string(n - y2, 'L');
                } else {
                    ans += 'U';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RDRU";
                    ans += string(n - y2 + 1, 'R');
                    ans += 'D';
                    ans += string(n - y2, 'L');
                }
            } else {
                ans += string(y1 - 1, 'L');
                if (x1 == 1) {
                    ans += 'D';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RURD";
                    if (y2 != n) {
                        ans.pop_back();
                        ans += string(n - y2, 'R');
                        ans += 'D';
                        ans += string(n - y2, 'L');
                    }
                } else {
                    ans += 'U';
                    ans += string(y1 - 1, 'R');
                    rep(i, 0, y2 - y1 >> 1) ans += "RDRU";
                    if (y2 != n) {
                        ans.pop_back();
                        ans += string(n - y2, 'R');
                        ans += 'U';
                        ans += string(n - y2, 'L');
                    }
                }
            }
            reverse(ans.begin(), ans.end());
            for (char c : ans) {
                if (c == 'R') cout << 'L';
                else if (c == 'L') cout << 'R';
                else if (c == 'U') cout << 'D';
                else if (c == 'D') cout << 'U';
            }
        }
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

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
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    string a, b;
    cin >> a >> b;
    string ra, rb;
    rep(i, 0, a.length()) {
        if (a[i] == ')') {
            int lr = ra.length();
            if (lr >= 3 && ra[lr - 3] == '(' && 
                ra[lr - 2] == 'x' && ra[lr - 1] == 'x') {
                ra.pop_back(); ra.pop_back(); ra.pop_back();
                ra += "xx";
            } else ra += a[i];
        } else ra += a[i];
    }
    rep(i, 0, b.length()) {
        if (b[i] == ')') {
            int lr = rb.length();
            if (lr >= 3 && rb[lr - 3] == '(' && 
                rb[lr - 2] == 'x' && rb[lr - 1] == 'x') {
                rb.pop_back(); rb.pop_back(); rb.pop_back();
                rb += "xx";
            } else rb += b[i];
        } else rb += b[i];
    }
    if (ra == rb) cout << "Yes";
    else cout << "No";
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

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
#define rrep(i, a, b) for (auto i = (a); i >= (b); --i)
#define AC return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3fLL;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 5'00'005;

void init() {

}

void solve() {
    ll a; int n; cin >> a >> n;
    vector<int> d(n);
    for (int& x : d) cin >> x;
    string s = to_string(a), pre;
    int m = s.size();
    char mn = char('0' + d.front());
    char mx = char('0' + d.back());
    ll ans = LINF;
    auto upd = [&](string t) {
        ll b = stoll(t);
        ans = min(ans, a > b ? a - b : b - a);
    };
    if (d.front() == 0) upd("0");
    if (m > 1 && d.back() != 0)
        upd(string(m - 1, mx));
    auto nz = upper_bound(d.begin(), d.end(), 0);
    if (nz != d.end())
        upd(string(1, char('0' + *nz)) + string(m, mn));
    rep(i, 0, m) {
        int x = s[i] - '0';
        auto p = lower_bound(d.begin(), d.end(), x);
        if (p != d.begin()) {
            int y = *prev(p);
            if (!(i == 0 && m > 1 && y == 0))
                upd(pre + char('0' + y) + string(m - i - 1, mx));
        }
        auto q = upper_bound(d.begin(), d.end(), x);
        if (q != d.end())
            upd(pre + char('0' + *q) + string(m - i - 1, mn));
        if (p == d.end() || *p != x) break;
        pre += s[i];
    }
    if (pre == s) ans = 0;
    cout << ans;
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

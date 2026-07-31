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

optional<string> build(
    string s,
    vector<int>& d,
    bool down
) {
    int m = s.size();
    vector<array<int, 2>> can(m + 1, array<int, 2>{0, 0});
    can[m][0] = can[m][1] = 1;
    auto legal = [&](int i, int tight, int x) {
        if (i == 0 && m > 1 && x == 0) return false;
        if (!tight) return true;
        int cur = s[i] - '0';
        return down ? x <= cur : x >= cur;
    };
    rrep(i, m - 1, 0) {
        rep(tight, 0, 2) {
            for (int x : d) {
                if (!legal(i, tight, x)) continue;
                int nt = tight && (x == s[i] - '0');
                if (can[i + 1][nt]) {
                    can[i][tight] = 1;
                    break;
                }
            }
        }
    }
    if (!can[0][1]) return nullopt;
    vector<int> order = d;
    if (down) reverse(order.begin(), order.end());
    string res;
    int tight = 1;
    rep(i, 0, m) {
        for (int x : order) {
            if (!legal(i, tight, x)) continue;
            int nt = tight && (x == s[i] - '0');
            if (can[i + 1][nt]) {
                res += char('0' + x);
                tight = nt;
                break;
            }
        }
    }
    return res;
}

void solve() {
    ull a; int n; cin >> a >> n;
    vector<int> d(n);
    for (int& x : d) cin >> x;
    string s = to_string(a);
    int m = s.size();
    auto lower = build(s, d, true);
    if (!lower && m > 1)
        lower = build(string(m - 1, '9'), d, true);
    if (!lower && d.front() == 0)
        lower = "0";
    auto upper = build(s, d, false);
    if (!upper)
        upper = build(string(m + 1, '0'), d, false);
    ull ans = ULLONG_MAX;
    if (lower) {
        ull b = stoll(*lower);
        ans = min(ans, a - b);
    }
    if (upper) {
        ull b = stoll(*upper);
        ans = min(ans, b - a);
    }
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

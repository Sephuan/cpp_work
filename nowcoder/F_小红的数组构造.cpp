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
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    ll n, x, k;
    cin >> n >> x >> k;
    if (k < n || k > n * x) {
        cout << "NO";
        return ;
    }
    vector<int> items;
    for (int l = 1, r; l <= x; l = r + 1) {
        int v = x / l;
        r = x / v;
        if (v > 1) items.push_back(v - 1);
    }
    int target = k - n;
    vector dp(target + 1, INF);
    vector fa(target + 1, -1);
    dp[0] = 0;
    for (int item : items) {
        rep1(w, item, target) {
            if (dp[w - item] + 1 < dp[w]) {
                dp[w] = dp[w - item] + 1;
                fa[w] = item;
            }
        }
    }
    if (dp[target] > n) {
        cout << "NO";
        return ;
    }
    cout << "YES" << endl;
    vector<int> ans;
    int cur = target;
    while (cur > 0) {
        int item = fa[cur];
        int v = item + 1;
        ans.push_back(x / v);
        cur -= item;
    }
    while (ans.size() < n) ans.push_back(x);
    rep(i, 0, n) cout << ans[i] << " "[i == n - 1];
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

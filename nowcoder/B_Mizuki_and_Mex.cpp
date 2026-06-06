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
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 100);
    vector<ll> pre(n + 100);
    rep1(i, 0, n) {
        cin >> a[i];
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    }
    if (pre[n] == 1) {
        int pos = 0;
        rep1(i, 1, n) {
            if (a[i]) pos = i;
        }
        cout << max(1, pos);
        return ;
    }
    ll ans = 0;
    auto chk = [&](int k) -> bool {
        ll ext = (k <= n) ? (pre[n] - (k ? pre[k - 1] : 0)): 0;
        ll need = 1;
        rrep(i, k - 1, 1) {
            if (need > a[i]) need += need - a[i];
            else ext += a[i] - need;
            if (need > 2e14) return false;
        }
        return ext + a[0] >= need;
    };
    int L = 0, R = n + 100;
    while (L <= R) {
        int mid = L + (R - L >> 1);
        if (chk(mid)) {
            ans = mid;
            L = mid + 1;
        } else R = mid - 1;
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

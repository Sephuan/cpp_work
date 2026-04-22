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
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n;
    cin >> n;
    vector<double> a(n + 1), pre(n + 1, 0);
    rep1(i, 1, n) cin >> a[i];
    if (n == 1) {
        cout << a[1];
        return ;
    }
    sort(a.begin() + 1, a.end());
    rep1(i, 1, n) {
        pre[i] = pre[i - 1] + a[i];
    }
    double E1 = (pre[n] * 2) / n;
    double ans = 0;
    rep1(i, 1, n) {
        double avg = (pre[n] - a[i]) / (n - 1);
        double E2 = 0;
        double sum = 0;
        int idx = upper_bound(a.begin() + 1, a.end(), avg) - a.begin();
        sum = (idx - 1) * avg + pre[n] - pre[idx - 1];
        if (idx > i) sum -= avg;
        else sum -= a[i];
        E2 = sum / (n - 1) + a[i];
        ans += max(E1, E2);
    }
    cout << ans / n;
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

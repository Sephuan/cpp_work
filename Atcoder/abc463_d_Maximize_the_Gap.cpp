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
    int N, K; cin >> N >> K;
    vector<pii> p(N);
    rep(i, 0, N) cin >> p[i].fi >> p[i].se;
    sort(p.begin(), p.end(), [&](auto& a, auto& b) {
        if (a.se != b.se) return a.se < b.se;
        return a.fi < b.fi;
    });
    int l = 1, r = 1e9;
    int ans = -1;
    while (l <= r) {
        int lst = -1e9;
        int mid = l + (r - l >> 1);
        int cnt = 0;
        rep(i, 0, N) {
            if (p[i].fi - lst >= mid) {
                lst = p[i].se;
                cnt ++;
            }
        }
        if (cnt >= K) {
            ans = max(ans, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
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

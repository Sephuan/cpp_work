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
    int n; cin >> n;
    map<int, vector<pii>> mx, my;
    map<pii, int> pts;
    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        pts[{x, y}] ++;
        mx[x].push_back({x, y});
        my[y].push_back({x, y});
    }
    int ans = 0;
    for (auto& [x, vp] : mx) {
        int sz = vp.size();
        if (sz < 2) continue;
        rep(i, 0, sz - 1) {
            rep(j, i + 1, sz) {
                int mid = vp[i].se + vp[j].se;
                if (mid & 1) continue;
                else mid >>= 1;
                if (!my.count(mid)) continue;
                int cnt = my[mid].size();
                ans += cnt;
                if (pts.count({x, mid})) ans -= 1;
            }
        }
    }
    for (auto& [y, vp] : my) {
        int sz = vp.size();
        if (sz < 2) continue;
        rep(i, 0, sz - 1) {
            rep(j, i + 1, sz) {
                int mid = vp[i].fi + vp[j].fi;
                if (mid & 1) continue;
                else mid >>= 1;
                if (!mx.count(mid)) continue;
                int cnt = mx[mid].size();
                ans += cnt;
                if (pts.count({mid, y})) ans -= 1;
            }
        }
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

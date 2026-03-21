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
const int MAXN = 1'00'005;

void init() {

}

struct pii_hash {
    inline size_t operator()(const pii& v) const {
        return 1LL * v.fi * MAXN + v.se;
    }
};

int h[MAXN];
map<int, vector<int>> cnt;
unordered_map<pii, int, pii_hash> both;
void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        h[a] ++; h[b] ++;
        if (a > b) swap(a, b);
        both[{a, b}] ++;
    }
    rep(i, 1, m + 1) {
        if (h[i]) cnt[h[i]].push_back(i);
    }
    auto it = cnt.rbegin();
    int ans = 0;
    if (it->se.size() == 1) {
        int prev = it->se[0];
        it ++;
        for (int curr : it->se) {
            pii p = {min(prev, curr), max(prev, curr)};
            int com = both.count(p) ? both[p] : 0;
            ans = max(ans, h[p.fi] + h[p.se] - com);
        }
    } else {
        auto& v = it->se;
        ll k = v.size();
        ll tot_p = k * (k - 1) >> 1;
        if (tot_p > n) {
            ans = it->fi << 1;
        } else rep(i, 0, v.size() - 1) rep(j, i + 1, v.size()) {
            pii p = {min(v[i], v[j]), max(v[i], v[j])};
            int com = both.count(p) ? both[p] : 0;
            ans = max(ans, h[p.fi] + h[p.se] - com);
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

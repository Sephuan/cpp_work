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

struct Seg {
    ll l, r;
};

void solve() {
    int n; ll t; cin >> n >> t;
    map<ll, ll> long_cnt;
    vector<Seg> short_segs;
    rep(i, 0, n) {
        ll l, r; cin >> l >> r;
        ll len = r - l;
        if (len > t) continue;
        if (len == t) long_cnt[l] ++;
        else short_segs.emplace_back(l, r);
    }
    ll ans = 0;
    for (auto& [l, cnt] : long_cnt) {
        ans += cnt * (cnt - 1) >> 1;
    }
    map<ll, ll> diff;
    for (auto& seg : short_segs) {
        diff[seg.r - t] ++;
        diff[seg.l + 1] --;
    }
    for (auto& [l, cnt] : long_cnt) diff[l] += 0;
    ll cur = 0;
    for (auto& [pos, delta] : diff) {
        cur += delta;
        if (long_cnt.count(pos)) {
            ans += cur * long_cnt[pos];
        }
    }
    map<ll, vector<ll>> left_r, right_l;
    for (auto& seg : short_segs) {
        left_r[seg.l].push_back(seg.r);
        right_l[seg.r - t].push_back(seg.l);
    }
    for (auto& [L, r_vec] : left_r) {
        auto it = right_l.find(L);
        if (it == right_l.end()) continue;
        auto& l_vec = it->se;
        ranges::sort(r_vec); ranges::sort(l_vec);
        int ptr = 0;
        for (ll r_val : r_vec) {
            while (ptr < l_vec.size() && l_vec[ptr] <= r_val) {
                ptr ++;
            }
            ans += ptr;
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

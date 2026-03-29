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

const double PI = acos(-1.0);
const int MAXN = 2'000'005;

void init() {

}

ll len(ll t) {
    int r = 0;
    while (t) {
        r ++;
        t /= 10;
    }
    return r;
}

ll pwl(ll len) {
    ll r = 1;
    while (len) {
        r *= 10;
        len --;
    }
    return r;
}

void solve() {
    ll tp[30], len_tp[30], pw10_tp[30];
    rep(i, 0, 30) {
        tp[i] = 1LL << i;
        len_tp[i] = len(tp[i]);
        pw10_tp[i] = pwl(len_tp[i]);
    }
    unordered_set<ll> vis;
    vector<ll> ans;

    auto dfs = [&](int stp, ll c_t, auto& self) {
        if (stp >= 30 || c_t > 1e9) return;
        if (c_t && !vis.count(c_t)) {
            vis.insert(c_t);
            ans.push_back(c_t);
        }
        rep(i, 0, 30) {
            ll n_t = c_t * pw10_tp[i] + tp[i];
            if (!vis.count(n_t))
                self(stp + 1, n_t, self);
        }
    };
    int N;
    cin >> N;
    dfs(0, 0, dfs);
    sort(ans.begin(), ans.end());
    cout << ans[N - 1];
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

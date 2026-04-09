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
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

struct pit {
    int l, r;
    bool operator<(auto& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos[1'005];
    rep1(i, 1, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    unordered_map<int, vector<pit>> um;
    rep1(i, 1, n) rep1(j, i + 1, n) {
        um[a[i] + a[j]].push_back({i, j});
    }
    int ans = 1;
    for (auto& [s, v] : um) {
        int siz = v.size();
        sort(v.begin(), v.end());
        vector<int> dp;
        rep(i, 0, siz) {
            int L = v[i].l;
            int R = v[i].r;
            int val = -R;
            auto it = lower_bound(dp.begin(), dp.end(), val);
            int cnt = 0;
            if (it == dp.end()) {
                dp.push_back(val);
                cnt = dp.size();
            } else {
                *it = val;
                cnt = it - dp.begin() + 1;
            }
            int len = cnt << 1;
            ans = max(ans, len);
            if (s % 2 == 0) {
                int mid_val = s >> 1;
                auto it_m = lower_bound(pos[mid_val].begin(), pos[mid_val].end(), L + 1);
                if (it_m != pos[mid_val].end() && *it_m < R) {
                    ans = max(ans, len + 1);
                }
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

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
const int MAXN = 2'00'005;

bool cmp(const pii& a, const pii& b) {
    int l_a = max(a.fi, a.se);
    int l_b = max(b.fi, b.se);
    if (l_a != l_b) return l_a < l_b;
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

vector<int> pw_2(40'005);

void init() {
    rep1(i, 1, 40'000) {
        pw_2[i] = i * i;
    }
}

vector<pii> res;
vector<pii> cand;
int n, k;

void solve() {
    cin >> n >> k;
    int a = upper_bound(pw_2.begin(), pw_2.end(), n) - pw_2.begin() - 1;
    int r = n - a * a;
    int max_k = 2 * a * (a - 1) + 2 * r - (r + a - 1) / a;
    if (k > max_k) {
        cout << "No";
        return ;
    }
    rep(i, 1, 600) rep(j, 1, 600) {
        cand.push_back({i, j});
    }
    sort(cand.begin(), cand.end(), cmp);
    cout << "Yes" << '\n';
    set<pii> vis;
    int idx = 0;
    int cur_k = 0;
    while (res.size() < n && cur_k < k) {
        pii p = cand[idx++];
        int add = 0;
        if (vis.count({p.fi - 1, p.se})) add ++;
        if (vis.count({p.fi, p.se - 1})) add ++;
        if (cur_k + add <= k) {
            cur_k += add;
            vis.insert(p);
            res.push_back(p);
        }
    }
    int far_y = 1;
    int const_x = 1e8;
    while (res.size() < n) {
        res.push_back({const_x, far_y});
        far_y += 2;
    }
    for (auto& p : res) {
        cout << p.fi << ' ' << p.se << '\n';
    }
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

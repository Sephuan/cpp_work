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
const int MAXN = 1'000'005;


void init() {

}

struct Fenwick {
    int n; vector<ll> tree;
    explicit Fenwick(int n) : n(n), tree(n + 1) {}
    void init() {
        tree.assign(n + 1, 0);
    }
    void add(int x, int v) {
        while (x <= n) {
            tree[x] += v;
            x += x & -x;
        }
    }
    ll preSum(int x) {
        ll ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= x & -x;
        }
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> v = a;
    ranges::sort(v);
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    Fenwick fw(m);
    vector<ll> L(n), R(n);
    vector<int> rank(n);
    rep(i, 0, n) {
        rank[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    rep(i, 0, n) {
        int r = rank[i];
        L[i] = i - fw.preSum(r);
        fw.add(r, 1);
    }
    fw.init();
    ll ans = 0;
    rrep(i, n - 1, 0) {
        int r = rank[i];
        R[i] = fw.preSum(r - 1);
        fw.add(r, 1);
        ans += L[i] * R[i];
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

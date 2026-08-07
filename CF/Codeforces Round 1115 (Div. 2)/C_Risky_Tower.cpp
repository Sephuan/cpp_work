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
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3fLL;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

struct Fenwick {
    int n; 
    vector<ll> sum;
    vector<int> cnt;
    explicit Fenwick(int n) : n(n), cnt(n + 1), sum(n + 1) {}
    void add(int pos, int c, ll s) {
        for (; pos <= n; pos += pos & -pos) {
            cnt[pos] += c;
            sum[pos] += s;
        }
    }
    pair<int, ll> pre(int pos) {
        int c = 0;
        ll s = 0;
        for (; pos > 0; pos -= pos & -pos) {
            c += cnt[pos];
            s += sum[pos];
        }
        return {c, s};
    }
    int mps(ll t) {
        int p = 0;
        ll cur = 0;
        int stp = 1;
        while ((stp << 1) <= n) stp <<= 1;
        for (; stp > 0; stp >>= 1) {
            int np = p + stp;
            if (np <= n && cur + sum[np] <= t) {
                p = np;
                cur += sum[np];
            }
        }
        return p;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);
    rep1(i, 1, n) cin >> v[i];
    vector a(n + 1, vector<int>(m));
    vector<int> all;
    rep1(i, 1, n) rep(j, 0, m) {
        cin >> a[i][j];
        all.push_back(a[i][j]);
    }
    ranges::sort(all);
    all.erase(unique(all.begin(), all.end()), all.end());
    int u = all.size();
    auto id = [&](ll x) {
        return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
    };
    Fenwick fw(u);
    int ans = m;
    int cnt = 0;
    ll sum = 0;
    rrep(k, n, 1) {
        for (ll x : a[k]) {
            fw.add(id(x), 1, x);
            cnt ++;
            sum += x;
        }
        if (sum < v[k]) continue;
        ll t = sum - v[k];
        int p = fw.mps(t);
        auto [c, s] = fw.pre(p);
        int extra = (t - s) / all[p];
        int need = cnt - c - extra;
        ans = min(ans, need);
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

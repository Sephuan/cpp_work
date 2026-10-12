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
#define all(x) (x).begin(), (x).end()
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

vector<int> pa(MAXN), sz(MAXN, 1);

int find(int u) {
    return pa[u] == u ? pa[u] : pa[u] = find(pa[u]);
}

void unite(int u, int v) {
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) return;
    int su = sz[fu], sv = sz[fv];
    if (su < sv) {
        swap(su, sv);
        swap(fu, fv);
    }
    pa[fv] = fu;
    sz[fu] += sv;
}

void init() {
    iota(all(pa), 0);
}

void solve() {
    int n; cin >> n;
    vector<int> c(n + 1);
    rep1(i, 1, n) cin >> c[i];
    vector<pii> vp;
    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        if (c[u] == c[v]) {
            unite(u, v);
        } else {    
            vp.push_back({u, v});
        }
    }
    map<int, vector<pii>> mp;
    for (auto [u, v] : vp) {
        int ru = find(u);
        int rv = find(v);
        mp[ru].push_back({rv, c[v]});
        mp[rv].push_back({ru, c[u]});  
    }
    ll ans = 0;
    for (auto& [i, vec] : mp) {
        ranges::sort(vec, [](auto a, auto b) {
            return a.se < b.se;
        });
        int j = 0, m = vec.size();
        while (j < m) {
            ll sum = sz[vec[j].fi];
            ll squre = 1LL * sz[vec[j].fi] * sz[vec[j].fi];
            int k = j + 1;
            while (k < m && vec[k].se == vec[j].se) {
                sum += sz[vec[k].fi];
                squre += 1LL * sz[vec[k].fi] * sz[vec[k].fi];
                k += 1;
            }
            ans += sum * sum - squre >> 1;
            j = k;
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

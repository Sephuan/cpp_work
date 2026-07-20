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

void solve() {
    int N, M; cin >> N >> M;
    vector<int> first(N + 1, INF);
    vector g(N + 1, vector<int>());
    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        if (u < v) first[v] = min(first[v], u);
    }
    vector<int> d(N + 1, INF);
    d[1] = 1;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({1, 1});
    while (!pq.empty()) {
        auto [cd, u] = pq.top(); pq.pop();
        if (cd != d[u]) continue ;
        for (auto v : g[u]) {
            int nd = max(cd, v);
            if (nd < d[v]) {
                d[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    vector<int> diff(N + 1);
    rep1(i, 2, N) {
        if (first[i] < i) {
            diff[first[i]] += 1;
            diff[i] -= 1;
        }
    }
    int cb = 0, preMax = 0;
    rep1(i, 1, N) {
        preMax = max(preMax, d[i]);
        cb += diff[i];
        if (preMax > i) cout << -1;
        else cout << cb;
        cout << endl;
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

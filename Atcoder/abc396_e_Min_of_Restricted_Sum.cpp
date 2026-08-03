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

void solve() {
    int N, M; cin >> N >> M;
    vector g(N, vector<pii>());
    rep(i, 0, M) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x - 1].push_back({y - 1, z});
        g[y - 1].push_back({x - 1, z});
    }
    vector<int> D(N, -1), A(N);
    bool ok = true;
    rep(i, 0, N) {
        if (D[i] != -1) continue;
        D[i] = 0;
        queue<int> q;
        vector<int> comp;
        q.push(i);
        while (!q.empty() && ok) {
            int u = q.front(); q.pop();
            comp.push_back(u);
            for (auto& [v, z] : g[u]) {
                int nd = z ^ D[u];
                if (D[v] == -1) {
                    D[v] = nd;
                    q.push(v);
                } else if (D[v] != nd) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) break;
        vector<int> cnt(30);
        for (auto& u : comp) rep(b, 0, 30) {
            if (D[u] >> b & 1) cnt[b] ++;
        }
        int sz = comp.size();
        int c = 0;
        rep(b, 0, 30) {
            if (cnt[b] * 2 > sz) {
                c |= 1 << b;
            }
        }
        for (auto& u: comp) {
            A[u] = D[u] ^ c;
        }
    }
    if (!ok) {
        cout << -1;
        return ;
    }
    rep(i, 0, N) {
        if (i) cout << ' ';
        cout << A[i];
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

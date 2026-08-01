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
#define rrep(i, a, b) for (auto i = (a); i >= (b); --i)
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
const int MAXN = 1'000'005;

void init() {

}

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        fa[rb] = ra;
        return true;
    }
};

void solve() {
    int N, M; cin >> N >> M;
    DSU dsu(N);
    vector<pii> red;
    rep1(i, 1, M) {
        int A, B; cin >> A >> B;
        if (!dsu.unite(A, B))
            red.push_back({i, A});
    }
    vector<int> rts;
    rep1(i, 1, N) if (dsu.find(i) == i) rts.push_back(i);
    int k = rts.size();
    cout << k - 1 << endl;
    int idx = 0;
    rep(i, 1, k) {
        auto [id, u] = red[idx ++];
        int ru = dsu.find(u);
        int ri = dsu.find(rts[i]);
        int r0 = dsu.find(rts[0]);
        if (ru == ri) {
            cout << id << ' ' << u << ' ' << rts[0];
            dsu.unite(r0, ri);
        } else {
            cout << id << ' ' << u << ' ' << ri;
            dsu.unite(ru, ri);
        }
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

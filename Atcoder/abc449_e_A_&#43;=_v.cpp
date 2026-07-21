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
    int n; vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    int kth(int k) {
        int pos = 0;
        int step = 1;
        while ((step << 1) <= n) step <<= 1;
        for (; step > 0; step >>= 1) {
            int nxt = pos + step;
            if (nxt <= n && bit[nxt] < k) {
                pos = nxt;
                k -= bit[nxt];
            }
        }
        return pos + 1;
    }
};

void solve() {
    int N, M; cin >> N >> M;
    vector<int> a(N + 1), freq(M + 1);
    rep1(i, 1, N) {
        cin >> a[i];
        freq[a[i]] ++;
    }
    vector<vector<int>> bucket(N + 1);
    rep1(v, 1, M) bucket[freq[v]].push_back(v);
    vector<int> levels, sizes;
    rep1(d, 0, N) {
        if (bucket[d].empty()) continue;
        levels.push_back(d);
        int curSize = bucket[d].size();
        if (!sizes.empty()) curSize += sizes.back();
        sizes.push_back(curSize);
    }
    int K = levels.size();
    vector<ll> start(K, 0);
    rep(i, 1, K) {
        start[i] = start[i - 1] + 1LL * (levels[i] - levels[i - 1]) * sizes[i - 1];
    }
    int Q; cin >> Q;
    vector<int> ans(Q);
    vector<vector<pii>> reqs(K);
    rep(qi, 0, Q) {
        ll X; cin >> X;
        if (X <= N) {
            ans[qi] = a[X];
            continue ;
        }
        ll p = X - N;
        int j = upper_bound(start.begin(), start.end(), p - 1) - start.begin() - 1;
        ll offset = p - start[j];
        if (j == K - 1) {
            ans[qi] = (offset - 1) % sizes[j] + 1;
        } else {
            int k = (offset - 1) % sizes[j] + 1;
            reqs[j].push_back({k, qi});
        }
    }
    Fenwick fw(M);
    rep(j, 0, K - 1) {
        for (int v : bucket[levels[j]]) {
            fw.add(v, 1);
        }
        for (auto [k, qi] : reqs[j]) {
            ans[qi] = fw.kth(k);
        }
    }
    for (int x : ans) cout << x << endl;
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

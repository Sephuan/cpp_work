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
    vector<int> A(N);
    for (int& x : A) cin >> x;
    vector<ll> bit(M + 1, 0);
    auto add = [&](int pos, ll val) -> void {
        for (int i = pos + 1; i <= M; i += i & -i)
            bit[i] += val;
    };
    auto prefix = [&](int pos) -> ll {
        ll res = 0;
        for (int i = pos + 1; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    };
    ll inv0 = 0;
    for (int x : A) {
        inv0 += prefix(M - 1) - prefix(x);
        add(x, 1);
    }
    vector<int> cnt(M), seen(M);
    for (int x : A) cnt[x] ++;
    vector<ll> delta(M);
    rep(p, 0, N) {
        int a = A[p];
        ll pd = p - seen[a];
        ll sd = (N - 1LL - p) - (cnt[a] - 1 - seen[a]);
        int k = M - 1 - a;
        delta[k] += pd - sd;
        seen[a] ++;
    }
    vector<ll> ans(M);
    ll cur = inv0;
    rep(k, 0, M) {
        ans[k] = cur;
        cur += delta[k];
    }
    rep(k, 0, M) cout << ans[k] << endl;
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

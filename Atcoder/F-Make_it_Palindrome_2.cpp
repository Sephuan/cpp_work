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
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 2, 0), B(N + 2, 0);
    vector<int> p((N + 2 >> 1) + 1, 0);
    rep1(i, 1, N) cin >> A[i];
    rep1(i, 1, N + 1) {
        B[i] = (A[i] - A[i - 1] + M) % M;
        (p[min(i, N + 2 - i)] += B[i]) %= M;
    }
    ll sum = accumulate(p.begin() + 1, p.end(), 0LL);
    ll t = sum / M;
    sort(p.begin() + 1, p.end(), greater<int>());
    ll ans = 0;
    rep1(i, 1, t) ans += M - p[i];
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

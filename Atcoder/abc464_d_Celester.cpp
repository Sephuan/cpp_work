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
    int N; cin >> N;
    string S; cin >> S;
    vector<ll> X(N), Y(N);
    rep(i, 0, N) cin >> X[i];
    rep(i, 0, N - 1) cin >> Y[i];
    ll dp[N][2];
    if (S[0] == 'R') {
        dp[0][0] = 0;
        dp[0][1] = -X[0];
    } else {
        dp[0][0] = -X[0];
        dp[0][1] = 0;
    }
    rep(i, 1, N) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0] + Y[i - 1], dp[i - 1][1]);
        if (S[i] == 'R') dp[i][1] -= X[i];
        else dp[i][0] -= X[i];
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]);
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
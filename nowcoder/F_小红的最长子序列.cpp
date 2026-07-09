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
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 205;

void init() {

}

int dp[MAXN][MAXN][MAXN];
bool used[MAXN][MAXN][MAXN];
int pre_j[MAXN][MAXN][MAXN], pre_k[MAXN][MAXN][MAXN];
int a[MAXN];

void solve() {
    int n, m; cin >> n >> m;
    rep1(i, 1, n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    rep1(i, 1, n) {
        rep(j, 0, m) {
            rep(k, 0, m) {
                if (dp[i - 1][j][k] != -1) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    used[i][j][k] = false;
                }
            }
        }
        ll p = 1;
        ll tmp = a[i];
        if (tmp == 0) p = 10 % m;
        else while (tmp > 0) {
            p = (p * 10) % m;
            tmp /= 10;
        }
        int v = a[i] % m;
        rep(j, 0, m) {
            rep(k, 0, m) {
                if (dp[i - 1][j][k] != -1) {
                    int nj = (j * p + v) % m;
                    int nk = (k + v) % m;
                    if (dp[i - 1][j][k] + 1 > dp[i][nj][nk]) {
                        dp[i][nj][nk] = dp[i - 1][j][k] + 1;
                        used[i][nj][nk] = true;
                        pre_j[i][nj][nk] = j;
                        pre_k[i][nj][nk] = k;
                    }
                }
            }
        }
    }
    int ans_len = -1;
    int ans_x = -1;
    rep(x, 0, m) {
        if (dp[n][x][x] > 0 && dp[n][x][x] > ans_len) {
            ans_len = dp[n][x][x];
            ans_x = x;
        }
    }
    if (ans_len == -1) {
        cout << 0;
        return ;
    }
    cout << ans_len << endl;
    vector<int> res;
    int cur_i = n;
    int cur_j = ans_x, cur_k = ans_x;
    while (cur_i > 0) {
        if (used[cur_i][cur_j][cur_k]) {
            res.push_back(a[cur_i]);
            int pj = pre_j[cur_i][cur_j][cur_k];
            int pk = pre_k[cur_i][cur_j][cur_k];
            cur_j = pj;
            cur_k = pk;
        }
        cur_i --;
    }
    reverse(res.begin(), res.end());
    rep(i, 0, res.size()) {
        if (i) cout << ' ';
        cout << res[i];
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

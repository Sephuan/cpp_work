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
#define Sephuan return 0;
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
const int MAXN = 10'000'005;

void init() {

}

void solve_() {
    int N, L; cin >> N >> L;
    vector<vector<vector<double>>> memo;
    vector<vector<vector<char>>> vis;
    vector<ll> A(N);
    ll sumA = 0.0;
    rep(i, 0, N) {
        cin >> A[i];
        sumA += A[i];
    }
    memo.assign(N + 1, vector (N + 1, vector<double>(L + 1, 0.0)));
    vis.assign(N + 1, vector (N + 1, vector<char>(L + 1, 0)));
    auto dfs = [&](auto&& self, int s, int m, int life) -> double {
        if (life == 0) return 0.0;
        if (s == 0 && m == 0) return 0.0;
        if (vis[s][m][life]) return memo[s][m][life];
        vis[s][m][life] = 1;
        int unseen = s + 2 * m;
        double val = 0.0;
        if (s > 0) {
            val += (double)s / unseen * (1.0 + self(self, s - 1, m, life));
        }
        if (m > 0) {
            int rem = unseen - 1;
            double inner = 0.0;
            inner += 1.0 / rem * (1.0 + self(self, s, m - 1, life));
            if (s > 0) {
                double gain = (life >= 2) ? 1.0 : 0.0;
                inner += (double)s / rem * (
                    gain + self(self, s, m - 1, life - 1));
            }
            if (m >= 2) {
                inner += (double)(2 * m - 2) / rem * 
                    self(self, s + 2, m - 2, life - 1);
            }
            val += (double)(2 * m) / unseen * inner;
        }
        return memo[s][m][life] = val;
    };
    double expPairs = dfs(dfs, 0, N, L);
    double ans = expPairs * ((double)sumA / N);
    cout << ans;
}

void solve() {
    int N, L; cin >> N >> L;
    vector<ll> A(N);
    ll sumA = 0;
    rep(i, 0, N) {
        cin >> A[i];
        sumA += A[i];
    }
    vector prev(N + 1, vector<double>(N + 1, 0.0));
    vector cur(N + 1, vector<double>(N + 1, 0.0));
    rep1(life, 1, L) {
        rep1(tot, 0, N) {
            rep1(s, 0, tot) {
                int m = tot - s;
                int unseen = s + 2 * m;
                if (unseen == 0) {
                    cur[s][m] = 0.0;
                    continue;
                }
                double val = 0.0;
                if (s > 0) {
                    val += (double)s / unseen * (1.0 + cur[s - 1][m]);
                }
                if (m > 0) {
                    double p2 = (double)(2 * m) / unseen;
                    int rem = unseen - 1;
                    double inner = 0.0;
                    inner += 1.0 / rem * (1.0 + cur[s][m - 1]);
                    if (s > 0) {
                        double gain = (life >= 2) ? 1.0 : 0.0;
                        inner += (double)s / rem * (gain + prev[s][m - 1]);
                    }
                    if (m >= 2) {
                        inner += (double)(2 * m - 2) / rem * prev[s + 2][m - 2];
                    }
                    val += p2 * inner;
                }
                cur[s][m] = val;
            }
        }
        swap(prev, cur);
        for (auto& row : cur) fill(row.begin(), row.end(), 0.0);
    }
    double expPairs = prev[0][N];
    double ans = expPairs * ((double)sumA / N);
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
        solve_();
        if (T) {
            cout << '\n';
        }
    }
    Sephuan
}

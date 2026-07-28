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
const int MAXN = 200'005;
const int N = 2'005;

int dif[N][N];
int pre[N][N];
int U[MAXN], D[MAXN], L[MAXN], R[MAXN]; 

void init() {
    int n; cin >> n;
    rep1(i, 1, n) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        dif[U[i]][L[i]]         ++;
        dif[U[i]][R[i] + 1]     --;
        dif[D[i] + 1][L[i]]     --;
        dif[D[i] + 1][R[i] + 1] ++;
    }
    ll zs = 0;
    rep1(r, 1, 2'000) {
        rep1(c, 1, 2'000) {
            dif[r][c] += dif[r - 1][c]
                + dif[r][c - 1] 
                - dif[r - 1][c - 1];
            if (dif[r][c] == 0) zs ++;
            int one = (dif[r][c] == 1);
            pre[r][c] = pre[r - 1][c]
                + pre[r][c - 1]
                - pre[r - 1][c - 1]
                + one;
        }
    }
    rep1(i, 1, n) {
        ll os = pre[D[i]][R[i]]
            - pre[U[i] - 1][R[i]]
            - pre[D[i]][L[i] - 1]
            + pre[U[i] - 1][L[i] - 1];
        cout << zs + os << endl;
    }
}

void solve() {

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

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

void printAns(const vector<string>& grid) {
    cout << "Yes\n";
    for (const string& row : grid) {
        cout << row << endl;
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int maxK = n * m + 1 >> 1;
    if (n == 1 || m == 1) {
        if (k < 0 || k > maxK) {
            cout << "No\n";
            return ;
        }
        vector<string> grid(n, string(m, '0'));
        if (n == 1) {
            rep(t, 0, k) grid[0][t << 1] = '1';
        } else {
            rep(t, 0, k) grid[t << 1][0] = '1';
        }
        printAns(grid);
        return ;
    }
    if (k < 1 || k > maxK) {
        cout << "No\n";
        return ;
    }
    int a = n + 1 >> 1, p = m + 1 >> 1;
    int mid = a * p;
    vector<string> grid(n, string(m, '0'));
    if (k <= a) {
        for (int i = 0; i < n; i += 2) {
            fill(grid[i].begin(), grid[i].end(), '1');
        }
        int extra = a - k;
        rep(t, 0, extra) {
            int row = 2 * t + 1;
            grid[row][0] = '1';
        }
    } else if (k <= mid) {
        int rem = k - a;
        for (int i = 0; i < n; i += 2) {
            int add = min(rem, p - 1);
            int runs = 1 + add;
            rem -= add;
            fill(grid[i].begin(), grid[i].end(), '1');
            rep(t, 1, runs) {
                int col = 2 * t - 1;
                grid[i][col] = '0';
            }
        }
    } else {
        rep(i, 0, n) rep(j, 0, m) {
            if ((i + j) % 2 == 0)   
                grid[i][j] = '1';
        }
        int extra = maxK - k;
        for (int i = 0; i < n && extra; i += 2) {
            for (int j = 0; j < m && extra; j += 2) {
                grid[i][j] = '0';
                extra --;
            }
        }
    }
    printAns(grid);
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

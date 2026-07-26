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
const int MAXN = 2'00'005;

void init() {

}

struct BIT {
    int n; vector<int> bit;
    explicit BIT(int n) : n(n), bit(n + 1, 0) {}
    void upd(int i, int val) {
        while (i <= n) {
            bit[i] = max(bit[i], val);
            i += i & -i;
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, bit[i]);
            i -= i & -i;
        }
        return res;
    }
};

void solve() {
    int N; cin >> N;
    vector<int> P(N + 1);
    rep1(i, 1, N) cin >> P[i];
    BIT bit(N);
    int curMax = 0;
    int R = 0;
    int L = 0;
    rep1(i, 1, N) {
        if (P[i] > curMax) {
            R ++;
            curMax = P[i];
        } else {
            int dp = bit.query(P[i] - 1) + 1;
            bit.upd(P[i], dp);
            L = max(L, dp);
        }
    }
    cout << R + L;
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

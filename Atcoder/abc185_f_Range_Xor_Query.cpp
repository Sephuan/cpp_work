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

struct Fenwick {
    int n; vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}
    void add(int x, int d) {
        while (x <= n) {
            bit[x] ^= d;
            x += x & -x;
        }
    }
    int preSum(int x) {
        int r = 0;
        while (x > 0) {
            r ^= bit[x];
            x -= x & -x;
        }
        return r;
    }
};

void init() {

}

void solve() {
    int N, Q; cin >> N >> Q;
    Fenwick fw(N);
    rep(i, 0, N) {
        int A;
        cin >> A;
        fw.add(i + 1, A);
    }
    while (Q --) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 1) {
            fw.add(X, Y);
        } else {
            cout << (fw.preSum(Y) ^ fw.preSum(X - 1)) << endl;
        }
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

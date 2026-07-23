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
#define int long long
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
    int n; cin >> n;
    vector<int> a(n);
    int X = 0;
    rep(i, 0, n) {
        cin >> a[i];
        X ^= a[i];
    }
    int M = ((1LL << 30) - 1) ^ X;
    vector<int> ma(n);
    rep(i, 0, n) ma[i] = a[i] & M;
    vector<int> basis(30);
    for (int& v : ma) rrep(i, 29, 0) {
        if (v & (1 << i)) {
            if (basis[i]) v ^= basis[i];
            else {
                basis[i] = v;
                break;
            }
        }
    }
    int res = 0;
    rrep(i, 29, 0) {
        int cand = res ^ basis[i];
        if (cand > res) res = cand;
    }
    int ans = X + 2 * res;
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

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
constexpr int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), dif(n + 1);
    ll sum = 0;
    rep1(i, 1, n) {
        cin >> a[i];
        if (i > 1) {
            dif[i] = ((a[i] - a[i - 1]) % 5 + 5) % 5;
            sum += dif[i];
        }
    }
    if (n == 1) {
        while (q --) {
            int l, r;
            cin >> l >> r;
            cout << 0 << endl;
        }
        return ;
    }
    while (q --) {
        int l, r; cin >> l >> r;
        if (l > 1) {
            sum -= dif[l];
            dif[l] += 1;
            dif[l] = (dif[l] % 5 + 5) % 5;
            sum += dif[l];
        }
        if (r < n) {
            sum -= dif[r + 1];
            dif[r + 1] -= 1;
            dif[r + 1] = (dif[r + 1] % 5 + 5) % 5;
            sum += dif[r + 1];
        }
        cout << sum << endl;
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

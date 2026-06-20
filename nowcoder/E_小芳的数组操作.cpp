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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll tot = 0;
    rep(k, 0, 30) {
        int cnt1 = 0;
        rep(i, 0, n) {
            if ((a[i] >> k) & 1) cnt1 ++;
        }
        if (cnt1 & 1) {
            cout << -1;
            return ;
        }
        int cur = INF;
        vector<int> bits(n);
        rep(i, 0, n) bits[i] = (a[i] >> k) & 1;
        int cnt = 0;
        rep(i, 0, n - 1) {
            if (bits[i]) {
                bits[i] ^= 1;
                bits[i + 1] ^= 1;
                cnt ++;
            }
        }
        if (bits[n - 1] == 0) {
            cur = min(cur, cnt);
        }
        fill(bits.begin(), bits.end(), 0);
        rep(i, 0, n) bits[i] = (a[i] >> k) & 1;
        bits[0] ^= 1;
        bits[n - 1] ^= 1;
        cnt = 1;
        rep(i, 0, n - 1) {
            if (bits[i]) {
                bits[i] ^= 1;
                bits[i + 1] ^= 1;
                cnt ++;
            }
        }
        if (bits[n - 1] == 0) {
            cur = min(cur, cnt);
        }
        tot += cur;
    }
    cout << tot;
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

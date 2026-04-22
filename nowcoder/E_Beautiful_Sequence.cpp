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

ll qpow(ll a, ll b) {
    b %= MOD_P;
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    rep1(i, 1, n) {
        int t;
        cin >> t;
        a[t] ++;
    }
    ll ans = 0;
    ll sum = 0;
    if (a[1]) {
        sum += qpow(2, n) - qpow(2, n - a[1]);
        sum %= MOD;
    }
    rep1(i, 2, n) {
        if (a[i]) {
            ll cnt = 0;
            for (ll j = i; j <= n; j += i) {
                cnt += a[j];
            }
            sum += qpow(2, cnt) - qpow(2, cnt - a[i]);
            sum %= MOD;
        }
    }
    ans = ((qpow(2, n) - 1 - sum) % MOD + MOD) % MOD;
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

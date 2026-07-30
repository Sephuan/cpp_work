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
#define rrep(i, a, b) for (auto i = (a); i >= (b); --i)
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
const int MAXN = 5'00'005;

void init() {

}

void solve() {
    int n; cin >> n;
    ll cnt1 = 0;
    ll ans = 0;
    vector<ll> cs;
    rep(i, 0, n) {
        ll c; cin >> c;
        if (c == 1) cnt1 ++;
        else {
            cs.push_back(c);
            ans += c;
        }
    }
    int m = cs.size();
    if (m == 0) { cout << 0; return; }
    else if (m == 1) {
        ans += min(cnt1, cs[0] >> 1);
    } else if (m > 1) {
        rep(i, 0, m) {
            cs[i] -= 2;
            while (cnt1 && cs[i] >= 2) {
                cs[i] -= 2;
                cnt1 --;
                ans ++;
            }
        }
    }
    if (ans < 3) {
        cout << 0;
        return ;
    }
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

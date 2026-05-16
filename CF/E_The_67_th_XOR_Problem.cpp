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
const int MAXN = 300'005 * 31;
int ch[MAXN][2];
int tot = 0;

void insert(int x) {
    int p = 0;
    rrep(i, 29, 0) {
        int bit = (x >> i) & 1;
        if (!ch[p][bit]) ch[p][bit] = ++tot;
        p = ch[p][bit];
    }
}

int query(int x) {
    int p = 0;
    int res = 0;
    rrep(i, 29, 0) {
        int bit = (x >> i) & 1;
        int ideal = !bit;
        if (ch[p][ideal]) {
            res += (1 << i);
            p = ch[p][ideal];
        } else p = ch[p][bit];
    }
    return res;
}

void init() {

}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    rep1(i, 0, tot) ch[i][0] = ch[i][1] = 0;
    tot = 0;
    int ans = 0;
    insert(a[0]);
    rep(i, 1, n) {
        ans = max(ans, query(a[i]));
        insert(a[i]);
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

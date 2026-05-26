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
    vector pos(n + 1, vector<int>());
    rep(i, 0, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    rep1(i, 1, n) {
        if (pos[i].size() > 2) {
            cout << -1;
            return ;
        }
    }
    vector b(n, 0), c(n, 0);
    vector vis_b(n + 1, false), vis_c(n + 1, false);
    int cnt = 0;
    rep1(i, 1, n) {
        if (pos[i].size() == 2) {
            int p1 = pos[i][0];
            int p2 = pos[i][1];
            b[p1] = i; vis_b[i] = true;
            c[p2] = i; vis_c[i] = true;
        } else if (pos[i].size() == 1) {
            int p = pos[i][0];
            if (cnt % 2 == 0) {
                b[p] = i; vis_b[i] = true;
            } else {
                c[p] = i; vis_c[i] = true;
            }
            cnt ++;
        }
    }
    vector<int> rb, rc;
    rep1(i, 1, n) {
        if (!vis_b[i]) rb.push_back(i);
        if (!vis_c[i]) rc.push_back(i);
    }
    int pb = 0, pc = 0;
    rep(i, 0, n) {
        if (b[i] == 0) b[i] = rb[pb ++];
        if (c[i] == 0) c[i] = rc[pc ++];
    }
    rep(i, 0, n) {
        if (i) cout << ' ';
        cout << b[i];
    }
    rep(i, 0, n) {
        if (i) cout << ' ';
        else cout << endl;
        cout << c[i];
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

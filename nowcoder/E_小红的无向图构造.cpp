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
    int n, m; cin >> n >> m;
    vector<pii> v;
    vector<vector<int>> dep(n);
    vector<pii> ans;
    rep1(i, 1, n) {
        int d; cin >> d;
        dep[d].push_back(i);
        v.push_back({i, d});
    }
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.se < b.se;
    });
    rep(i, 1, n) {
        if (dep[v[i].se - 1].empty()) {
            cout << -1;
            return ;
        }
        ans.push_back({dep[v[i].se - 1][0], v[i].fi});
    }
    rep(i, 0, n) {
        if (ans.size() == m) {
            for (auto& [u, v] : ans) {
                cout << u << ' ' << v << endl;
            }
            return ;
        }
        if (dep[i].size() == 0) break;
        if (dep[i].size() > 1) {
            rep(j, 0, dep[i].size() - 1) {
                rep(k, j + 1, dep[i].size()) {
                    ans.push_back({dep[i][j], dep[i][k]});
                    if (ans.size() == m) {
                        for (auto& [u, v] : ans) {
                            cout << u << ' ' << v << endl;
                        }
                        return ;
                    }
                }
            }
            rep(j, 1, dep[i].size()) {
                int k = i + 1;
                if (k < n) {
                    if (dep[k].size() == 0) break;
                    rep(l, 0, dep[k].size()) {
                        ans.push_back({dep[i][j], dep[k][l]});
                        if (ans.size() == m) {
                            for (auto& [u, v] : ans) {
                                cout << u << ' ' << v << endl;
                            }
                            return ;
                        }
                    }
                }
            }
        }
    }
    cout << -1;
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

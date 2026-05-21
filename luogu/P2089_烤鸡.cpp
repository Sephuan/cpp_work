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

vector<vector<int>> ans;
vector<int> cur;
int n;

void dfs(int idx, int sum) {
    if (sum > n || sum + (10 - idx) * 3 < n) return ;
    if (idx == 10) {
        if (sum == n) ans.push_back(cur);
        return ;
    }
    rep1(i, 1, 3) {
        cur.push_back(i);
        dfs(idx + 1, sum + i);
        cur.pop_back();
    }
}

void solve() {
    cin >> n;
    if (n < 10 || n > 30) cout << 0;
    else {
        dfs(0, 0);
        cout << ans.size() << endl;
        for (auto& v : ans) {
            rep(i, 0, 10) {
                if (i) cout << ' ';
                cout << v[i];
            }
            cout << endl;
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

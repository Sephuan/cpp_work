#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define AC return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 5'005;

void init() {

}

vector<ll> dp(MAXN);
vector<int> deg(MAXN);
vector<int> out(MAXN);
vector<int> edge[MAXN];
void solve() {
    int n, m;
    cin >> n >> m;
    
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        deg[b] ++;
        out[a] ++;
        edge[a].push_back(b);
    }
    ll ans = 0;
    queue<int> q;
    rep1(i, 1, n) if (deg[i] == 0) {q.push(i); dp[i] = 1;}
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i : edge[t]) {
            dp[i] = (dp[i] + dp[t]) % 8011'2002;
            deg[i] --;
            if (deg[i] == 0) q.push(i);
        }
    }
    rep1(i, 1, n) if (out[i] == 0) ans = (ans + dp[i]) % 8011'2002;
    cout << ans;
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

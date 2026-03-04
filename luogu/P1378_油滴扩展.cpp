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

const double PI = acos(-1);
const int MAXN = 2'00'005;

void init() {

}

double max_a = 0.0;
vector<pii> vp;
int N;
bool vis[10];
double R[10];
int minX, minY, maxX, maxY;

double dis(int a, int b) {
    double dx = vp[a].fi - vp[b].fi;
    double dy = vp[a].se - vp[b].se;
    return sqrt(dx * dx + dy * dy);
}

void dfs(int step, double cur) {
    if (step == N) {
        max_a = max(cur, max_a);
        return ;
    }
    rep(i, 0, N) {
        if (!vis[i]) {
            double r = min({
                abs(vp[i].fi - minX), abs(vp[i].fi - maxX),
                abs(vp[i].se - minY), abs(vp[i].se - maxY)
            });
            rep(j, 0, N) {
                if (vis[j]) {
                    double d = dis(j, i);
                    r = min(r, max(0.0, d - R[j]));
                }
            }
            vis[i] = true;
            R[i] = r;
            dfs(step + 1, cur + PI * r * r);
            vis[i] = false;
            R[i] = 0.0;
        }
    }

}

void solve() {
    cin >> N;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    maxX = max(x1, x2); minX = min(x1, x2);
    maxY = max(y1, y2); minY = min(y1, y2);
    rep(i, 0, N) {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    dfs(0, 0.0);
    cout << (int)round((maxX - minX) * (maxY - minY) - max_a);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    //cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

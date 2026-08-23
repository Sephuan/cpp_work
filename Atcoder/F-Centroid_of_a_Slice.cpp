#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define Sephuan return 0;
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
const int MAXN = 200'005;

void init() {

}

struct pts {
	ll x, y;
};
using llf = long double;

constexpr ll cross(pts& a, pts& b) {
	return a.x * b.y - a.y * b.x;
}

void solve() {
	int n, q;  cin >> n >> q;
	vector<pts> p(2 * n + 1);
	rep1(i, 1, n) {
		cin >> p[i].x >> p[i].y;
		p[i + n] = p[i];
	}
	vector<ll> preD(2 * n + 1), preX(2 * n + 1), preY(2 * n + 1);
	rep(i, 1, 2 * n) {
		ll d = cross(p[i], p[i + 1]);
		preD[i] = preD[i - 1] + d;
		preX[i] = preX[i - 1] + (p[i].x + p[i + 1].x) * d;
		preY[i] = preY[i - 1] + (p[i].y + p[i + 1].y) * d;
	}
	while (q --) {
		int u, v; cin >> u >> v;
		if (v < u) v += n;
		ll D = preD[v - 1] - preD[u - 1];
		ll X = preX[v - 1] - preX[u - 1];
		ll Y = preY[v - 1] - preY[u - 1];
		ll d = cross(p[v], p[u]);
		D += d;
		X += (p[v].x + p[u].x) * d;
		Y += (p[v].y + p[u].y) * d;
		llf gx = (llf)X / (3.0L * D);
		llf gy = (llf)Y / (3.0L * D);
		cout << gx << ' ' << gy << endl;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    Sephuan
}

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

void solve() {
	int N, M; cin >> N >> M;
	vector g(N + 1, vector<int>());
	rep(i, 0, M) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector color(N + 1, -1), depth(N + 1, 0), root(N + 1, -1);
	color[1] = 0;
	queue<int> q;
	q.push(1);
	int s = -1, t = -1;
	while (!q.empty() && s == -1) {
		int u = q.front(); q.pop();
		for (int& v : g[u]) {
			if (color[v] == -1) {
				q.push(v);
				root[v] = u;
				color[v] = color[u] ^ 1;
				depth[v] = depth[u] + 1;
			} else if (color[v] == color[u]) {
				s = u;
				t = v;
				break;
			}
		}
	}
	if (s == -1) {
		cout << -1;
		return ;
	}
	vector<int> left, right;
	while (depth[s] > depth[t]) {
		left.push_back(s);
		s = root[s];
	}
	while (depth[t] > depth[s]) {
		right.push_back(t);
		t = root[t];
	}
	while (s != t) {
		left.push_back(s);
		right.push_back(t);
		s = root[s];
		t = root[t];
	}
	left.push_back(s);
	left.insert(left.end(), right.rbegin(), right.rend());
	cout << left.size() << endl;
	rep(i, 0, left.size()) {
		if (i) cout << ' ';
		cout << left[i];
	}
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
    Sephuan
}

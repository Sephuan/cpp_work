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

struct Mat {
	ll a[4][4];
	Mat(int one = 0) {
		memset(a, 0, sizeof a);
		if (one) {
			for (int i = 0; i < 4; ++ i) a[i][i] = 1;
		}
	}
};

Mat mul(Mat& x, Mat& y) {
	Mat z;
	for (int i = 0; i < 4; ++ i) {
		for (int k = 0; k < 4; ++ k) {
			if (x.a[i][k] == 0) continue;
			for (int j = 0; j < 4; ++j) {
				if (y.a[k][j] == 0) continue;
				z.a[i][j] = (z.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
			}
		}
	}
	return z;
}

Mat mpow(Mat base, ll e) {
	Mat res(1);
	while (e) {
		if (e & 1) res = mul(res, base);
		base = mul(base, base);
		e >>= 1;
	}
	return res;
}

void solve() {
	ll n; int r;
	cin >> n >> r;
	Mat t;
	rep(i, 0, 4) {
		t.a[i][i] = (t.a[i][i] + 1) % MOD;
		t.a[(i + 1) % 4][i] = (t.a[(i + 1) % 4][i] + 1) % MOD;
		t.a[(i + 3) % 4][i] = (t.a[(i + 3) % 4][i] + 1) % MOD;
	}
	Mat ans = mpow(t, n);
	cout << ans.a[r][0] % MOD;
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

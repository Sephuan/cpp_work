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
const int MAXN = 1'000'005;

int N, K;
string S;
vector<int> P;

bool chk(double x) {
    int ptr = -1;
    double min_v = 1e100;
    rep1(r, 1, N) {
        while (ptr + 1 < r && P[ptr + 1] <= P[r] - K) {
            ++ ptr;
            double v = P[ptr] - x * ptr;
            if (v < min_v) min_v = v;
        }
        double vr = P[r] - x * r;
        if (min_v <= vr) return true;
    }
    return false;
}

void init() {
    cin >> N >> K;
    cin >> S;
    P.assign(N + 1, 0);
    rep1(i, 1, N) {
        P[i] = P[i - 1] + (S[i - 1] == 'o');
    }
}

void solve() {
    double lo = 0.0, hi = 1.0;
    rep(it, 0, 50) {
        double mid = (lo + hi) / 2.0;
        if (chk(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
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

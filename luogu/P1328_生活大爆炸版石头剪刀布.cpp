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
    auto cal = [&](int a, int b) -> pii {
        if (a == b) return {0, 0};
        int f = 0;
        int ra = 0, rb = 0;
        if (a > b) {swap(a, b); f = 1;}
        if (a == 0) {
            if (b == 1 || b == 4) rb = 1;
            else ra = 1;
        } else if (a == 1) {
            if (b == 2 || b == 4) rb = 1;
            else ra = 1;
        } else if (b == 3) rb = 1;
        else ra = 1;
        if (f) swap(ra, rb);
        return {ra, rb};
    };
    int N, Na, Nb; cin >> N >> Na >> Nb;
    vector<int> va(Na), vb(Nb);
    rep(i, 0, Na) cin >> va[i];
    rep(i, 0, Nb) cin >> vb[i];
    int ans_a = 0, ans_b = 0;
    rep(i, 0, N) {
        auto [ra, rb] = cal(va[i % Na], vb[i % Nb]);
        ans_a += ra, ans_b += rb;
    }
    cout << ans_a << ' ' << ans_b;
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

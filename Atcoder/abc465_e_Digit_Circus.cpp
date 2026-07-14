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

const int MASKS = 1 << 10;
int dp[2][3][MASKS];
int ndp[2][3][MASKS];
int nxtMask[MASKS][10];
int nxtRem[3][10];

void init() {

}

void solve() {
    string N; cin >> N;
    rep(mask, 0, MASKS) {
        rep1(d, 0, 9) {
            if (mask == 0 && d == 0)
                nxtMask[mask][d] = 0;
            else
                nxtMask[mask][d] = mask | (1 << d);
        }
    }
    rep(rem, 0, 3) {
        rep1(d, 0, 9) {
            nxtRem[rem][d] = (rem * 10 + d) % 3;
        }
    }
    dp[1][0][0] = 1;
    for (char ch : N) {
        memset(ndp, 0, sizeof ndp);
        int bound = ch - '0';
        rep1(tight, 0, 1) {
            int upper = tight ? bound : 9;
            rep(rem, 0, 3) {
                rep(mask, 0, MASKS) {
                    int ways = dp[tight][rem][mask];
                    if (ways == 0) continue;
                    rep1(d, 0, upper) {
                        int newTight = tight && (d == bound);
                        int newRem = nxtRem[rem][d];
                        int newMask = nxtMask[mask][d];
                        int &target = ndp[newTight][newRem][newMask];
                        target += ways;
                        if (target >= MOD) target -= MOD;
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof dp);
    }
    int ans = 0;
    rep1(tight, 0, 1) {
        rep(rem, 0, 3) {
            rep(mask, 1, MASKS) {
                int A = (rem == 0);
                int B = ((mask & (1 << 3)) != 0);
                int C = (__builtin_popcount(mask) == 3);
                if (A + B + C == 1) {
                    ans += dp[tight][rem][mask];
                    if (ans >= MOD) ans -= MOD;
                }
            }
        }
    }
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

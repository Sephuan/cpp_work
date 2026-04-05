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
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N + 1), B(M + 1), preA(N + 1, 0);
    ll ma = 0, mb = 0;
    rep1(i, 1, N) {
        cin >> A[i];
        preA[i] = preA[i - 1] + A[i];
        (ma += A[i] * i) %= MOD;
    }
    rep1(i, 1, M) {
        cin >> B[i];
        (mb += B[i]) %= MOD;
    }
    ll p1 = ma * mb % MOD;
    ll p2 = 0;
    rep1(j, 1, M) {
        ll ins = 0;
        for (int k = 1; k * j <= N; ++k) {
            ins += (preA[min((k + 1) * j - 1, N)] - preA[k * j - 1]) * k % MOD;
            ins %= MOD;
        }
        (p2 += B[j] * j % MOD * ins % MOD) %= MOD;
    }
    cout << (p1 - p2 + MOD) % MOD;
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

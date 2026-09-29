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
#define int long long
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
const int MAXN = 2'00'005;

void init() {

}

using u32 = uint32_t;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> Z(n);
    int L = 0, R = 0;
    rep(i, 1, n) {
        if (i < R) Z[i] = min(R - i, Z[i - L]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i] ++;
        if (i + Z[i] > R) {
            L = i;
            R = i + Z[i];
        }
    }
    u32 succ[26] = {};
    u32 present = 0;
    for (char& c : s) present |= 1u << (c - 'a');
    rep(i, 1, n) {
        if (Z[i] == n - i) { cout << 0 << '\n'; return ; }
        int a = s[Z[i]] - 'a', b = s[i + Z[i]] - 'a';
        succ[a] |= 1u << b;
    }
    u32 reach[26];
    rep(i, 0, 26) reach[i] = succ[i];
    rep(k, 0, 26) rep(i, 0, 26)
        if (reach[i] & (1u << k)) reach[i] |= reach[k];
    rep(i, 0, 26) if (reach[i] & (1u << i)) {
        cout << 0;
        return ;
    }
    int id[26]; fill(id, id + 26, -1);
    int m = 0;
    rep(c, 0, 26) if (present & (1u << c)) id[c] = m ++;
    u32 succM[26] = {};
    rep(c, 0, 26) if (id[c] != -1) {
        u32 t = succ[c];
        while (t) {
            int w = __builtin_ctz(t);
            t &= t - 1;
            if (id[w] != -1) succM[id[c]] |= 1u << id[w];
        }
    }
    int full = 1 << m;
    vector<u32> dp(full, 0);
    dp[0] = 1;
    rep(mask, 1, full) {
        u32 sum = 0;
        for (int sub = mask; sub; sub &= sub - 1) {
            int e = __builtin_ctz(sub);
            if ((succM[e] & (u32)mask) == 0)
                sum += dp[mask ^ (1u << e)];
        }
        dp[mask] = sum;
    }
    u32 ans = dp[full - 1];
    rep1(f, m + 1, 26) ans *= (u32)f;
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

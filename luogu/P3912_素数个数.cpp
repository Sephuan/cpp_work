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

const int MAXN = 2'00'005;

int p[6'000'000], cnt;
bitset<static_cast<int>(1e8+10)> st;

void init() {

}

void solve() {
    int N;
    cin >> N;
    rep1(i, 2, N) {
        if (!st[i]) p[++cnt] = i;
        for (int j = 1; p[j] <= N / i; ++j) {
            st[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
    cout << cnt;
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

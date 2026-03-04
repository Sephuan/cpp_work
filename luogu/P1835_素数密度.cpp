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

const int MAXN = 1'000'000;

int p[5'0000], cnt;
bitset<MAXN> st;

void gp(int n) {
    rep1(i, 2, n) {
        if (!st[i]) {
            p[cnt++] = i;
            for (ll j = (ll)i * i; j <= n; j += i)
                st[j] = 1;
        }
    }
}

void init() {
    
}

void solve() {
    int L, R;
    cin >> L >> R;
    int sr = sqrt(R) + 1;
    gp(sr);
    vector<bool> mark(R - L + 1, true);
    for (int idx = 0; idx < cnt; ++idx) {
        int i = p[idx];
        ll l = max((ll)i * i, (ll)(L + i - 1) / i * i);
        for (ll j = l; j <= R; j += i)
            mark[j - L] = false;
    }
    int ans = count(mark.begin(), mark.end(), true);
    cout << (L == 1 ? ans - 1 : ans);
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

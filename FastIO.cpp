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

namespace FastIO {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline char gc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    inline int read() {
        int x = 0; char c = gc();
        while (c < '0' || c > '9') c = gc();
        while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = gc();}
        return x;
    }
}
//using FastIO::read; // Linux: Ctrl+D, Win: Ctrl+Z

// 普通版快读（本地调试友好）
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch - '0'); // 等价于 x * 10 + (ch - '0')
        ch = getchar();
    }
    return x * f;
}

void init() {

}

void solve() {
    int n = read();
    cout << n;
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

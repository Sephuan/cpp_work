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

/*
在数学上，从 1 到某个正整数 x 的区间内，
k 的倍数
（也就是除以 k 余数为 0 的数）的个数，
就是简单的向下取整：x / k。
*/



void solve() {
    ll l, r, k; cin >> l >> r >> k;
    ll len = r - l + 1;
    ll base = len / k;
    ll rem = len % k;
    auto cal = [](ll n) {return n * (n - 1) >> 1;};
    ll ans = rem * cal(base + 1) + (k - rem) * cal(base);
    cout << ans;
}

/*
核心定理总结这道题表面上是在考代码，实际上是依靠三个坚实的数学定理支撑起来的：
异或与 $2$ 的次幂定理（转化条件）定理：
如果 $k = 2^p$，那么 $i \oplus j$ 是 $k$ 的倍数 $\iff i$ 和 $j$ 除以 $k$ 的余数相同（即 $i \equiv j \pmod{k}$）。

本质：因为余数相同，它们二进制的末尾 $p$ 位完全一致，异或后末尾 $p$ 位全部清零，
自然就成了 $2^p$ 的倍数。

连续整数同余分布定理（化繁为简）定理：
对于任意长度为 $len$ 的连续整数区间，将其对 $k$ 取模，
各个余数（$0$ 到 $k-1$）出现的次数极其均匀，最大次数与最小次数之差最多为 $1$。

本质：这就是你代码中 len / k（保底次数）和 len % k（多出一次的余数个数）的数学基础。
它让我们彻底摆脱了 $O(N)$ 的遍历，直接用 $O(1)$ 的时间算出桶的分布。

组合数学原理（计算结果）定理：从 $n$ 个相同的元素中任选 $2$ 个，
组合数为 $\frac{n \times (n - 1)}{2}$。

本质：同一个“余数桶”里的任意两个数字配对都合法。
*/

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

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
constexpr int ddx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int ddy[] = {0, 0, -1, 1, -1, 1, 1, -1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 200'005;

// ==========================================
// 线性基 (Linear Basis)
// 核心应用：
// 1. 子集异或最大值 (queryMax)
// 2. 子集异或最小值 (queryMin)
// 3. 判定某数能否由原集合的子集异或表示 (contains)
// 4. 子集异或第 k 小 (queryKth)
// 5. 树链剖分/线段树合并线性基 (merge)
// 复杂度：
// 插入/查询/判定: O(BITS)
// 重构正交基: O(BITS^2)
// ==========================================
struct LinearBasis {
    static const int BITS = 62; // 适用于 0 ~ 2^62-1 (标准 long long 范围)
    ll p[BITS + 1];             // 基底数组：p[i] 表示最高位为第 i 位的基底数值
    vector<ll> d;               // 高斯消元后的正交基底，用于支持 O(log N) 查询第 k 小
    int cnt;                    // 基底中的主元数量（空间维数）
    bool has_zero;              // 记录原集合是否能异或出 0（或本身含有 0）

    LinearBasis() {
        init();
    }

    void init() {
        memset(p, 0, sizeof(p));
        d.clear();
        cnt = 0;
        has_zero = false;
    }

    // 1. 插入一个数 x
    // 返回值：true 表示成功扩展了基底空间；false 表示 x 线性相关（可被已有基底凑出）
    bool insert(ll x) {
        for (int i = BITS; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (!p[i]) {
                    p[i] = x;
                    cnt++;
                    return true;
                }
                x ^= p[i]; // 将 x 的第 i 位消为 0
            }
        }
        has_zero = true; // 无法扩展基底，说明原集合子集异或和可得到 0
        return false;
    }

    // 2. 查询子集能异或出的【最大值】
    // initial_val: 基础初值（例如在求图上 1 到 n 的最大异或路径时，传入一条固定简单路径的异或和）
    ll queryMax(ll initial_val = 0) {
        ll ans = initial_val;
        for (int i = BITS; i >= 0; --i) {
            ans = max(ans, ans ^ p[i]); // 贪心：若异或能使当前位变 1，则必定异或
        }
        return ans;
    }

    // 3. 查询子集能异或出的【非零最小值】
    // 说明：如果题目允许空集或集合元素能凑出 0，请先根据 has_zero 判定
    ll queryMin() {
        if (has_zero) return 0;
        for (int i = 0; i <= BITS; ++i) {
            if (p[i]) return p[i];
        }
        return 0;
    }

    // 4. 判定数值 x 是否能由当前集合的某个非空子集异或凑出
    bool contains(ll x) {
        if (x == 0) return has_zero;
        for (int i = BITS; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (!p[i]) return false; // 无法消去该位，说明凑不出 x
                x ^= p[i];
            }
        }
        return true;
    }

    // 5. 重构正交高斯矩阵（内部使用，将高位的 p[i] 对所有低位 p[j] 消元）
    void rebuild() {
        d.clear();
        ll tmp[BITS + 1];
        memcpy(tmp, p, sizeof(p));
        for (int i = BITS; i >= 0; --i) {
            if (!tmp[i]) continue;
            for (int j = i - 1; j >= 0; --j) {
                if ((tmp[i] >> j) & 1) tmp[i] ^= tmp[j];
            }
        }
        for (int i = 0; i <= BITS; ++i) {
            if (tmp[i]) d.push_back(tmp[i]);
        }
    }

    // 6. 查询子集能异或出的【第 k 小异或和】 (1-based)
    // 前提：
    // 1. 1 <= k <= 集合能张成的非重复异或和总数
    // 2. 0 若能凑出则占第 1 小；其余数按 k 的二进制位直接映射到正交向量基上
    ll queryKth(ll k) {
        if (d.empty()) rebuild();
        if (has_zero) k--;
        if (k == 0) return 0;
        if (d.size() < 62 && k >= (1LL << d.size())) return -1; // k 超过最大可能组合数
        ll ans = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            if ((k >> i) & 1) ans ^= d[i];
        }
        return ans;
    }

    // 7. 合并另一个线性基 other（将 other 的所有主元重新 insert 进来）
    void merge(const LinearBasis& other) {
        for (int i = BITS; i >= 0; --i) {
            if (other.p[i]) insert(other.p[i]);
        }
        if (other.has_zero) has_zero = true;
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    LinearBasis lb;
    rep(i, 0, n) {
        ll x;
        cin >> x;
        lb.insert(x);
    }
    cout << lb.queryMax() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) cout << '\n';
    }
    Sephuan
}

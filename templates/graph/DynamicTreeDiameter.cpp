#include <bits/stdc++.h>
using namespace std;

/*

结论
这个模板是「静态树 + 动态点集直径」这一类问题的标准通用结构，但它的通用是有明确边界的：
树结构必须固定、维护的量必须是直径。它依赖两条只在树上成立的性质：
- 端点引理：设 (a,b) 是集合 S 的直径端点，
则对任意 x，max_{y in S} dist(x,y) = max{dist(x,a), dist(x,b)}；
- 合并引理：diam(A union B) = max{diam(A), diam(B), max_{i,j} dist(a_i,b_j)}。
这两条在树度量下成立，在一般图、环、任意度量空间里不成立。
所以模板的本质是：树 + 直径 + 任意增删切换，三者缺一不可。

适用场景
1️⃣ 任意增/删/切换 + 每次操作后查直径（主要用途）
典型的题目形态：树上节点被「激活/熄灭」，动态询问当前激活点集的直径。
模板单次操作 O(log n)，是这类题的标配做法。

2️⃣ 需要在线回答、不能离线的场景
每次操作只依赖当前集合状态，天然支持在线；输入边读边处理也可以。

3️⃣ 「强制加入单点」的批量查询
就是你的 solve() 里 for i 插入 → 查询 → 撤销的模式。
模板能过，但属于杀鸡用牛刀——这种「只加一个点再撤销」的形态，
上一轮给的 O(n) 两次 BFS 更快更短，是本题的推荐解。

4️⃣ 两个值得知道的扩展方向
- 带权边：需要把「深度」拆成两个数组——一个用边数深度（给 RMQ 求 LCA 用），
另一个用根到点的带权和（给 dist 用），dist 公式本身不用动。
模板注释里写的「带权可自行修改 dist 函数」指的就是这个。
- 子树区间查询：把线段树下标从「节点编号」换成 dfn 序，
配合区间查询（merge 是可结合的），
就能回答「某棵子树内所有特殊点的直径」——子树恰好对应 dfn 连续区间 [tin(u), tout(u)]。
你最初那个模板用 dfn 建环，反而有这个潜力；修复版按节点编号建，丢掉了这一点，需要时可以改回去。

不适用 / 要小心的场景
❌ 树本身会变（加边、删边、换根）
欧拉序、RMQ、LCA 全部失效，需要 Link-Cut Tree 等更重的结构。

❌ 非树图（有环、一般图）
端点引理直接不成立。比如环上三个点两两距离相等，任取一个直径端点对，
第三个点可能才是最远的，合并就会出错。

❌ 维护的不是「直径」
比如要维护最近点对、重心、集合内所有点对距离之和——这些量的 merge 性质完全不同，
不能套这个模板。

⚠️ 只插入不删除（单调）
如果点只加不删，直接维护一个直径端点对 (a,b)，
插入 x 时只需比较 (a,b)、(x,a)、(x,b) 三个候选，复杂度 O(log n) 且代码短得多；
线段树是多余的。

⚠️ 节点规模极大时注意内存
RMQ 稀疏表是 O(n log n) 空间，n=2e5 时约 30MB，
到 n=1e6 会逼近 170MB，需要换别的 O(1) LCA 实现或改二进制倍增 + 牺牲一点常数。

一句话总结
这个模板的定位是：树固定、点集任意增删切换、要动态直径——在这条赛道上它是通用且正确的；
离开这条赛道（树会变、图不是树、维护的不是直径），就得换思路。
如果只是本题这种「单点强制加入」，用 O(n) 两次 BFS 才是最优解。

*/

/*
 * 类名：DynamicTreeDiameter
 * 功能：固定树上，动态维护特殊点集合的直径，支持增、删、切换
 * 原理：线段树按下标（节点编号）维护每个区间内特殊点集合的直径端点与直径值。
 *       合并两个集合 A、B 时（直径端点分别为 a1,a2 与 b1,b2）：
 *          diam(A∪B) = max( diam(A), diam(B),
 *                           dist(a1,b1), dist(a1,b2),
 *                           dist(a2,b1), dist(a2,b2) )
 * 复杂度：预处理 O(n log n)，每次增/删/切换 O(log n)
 *        （LCA 用欧拉序 + RMQ，O(1) 查询）
 * 注意：节点编号为 1 ~ n，边权默认为 1，带权可自行修改 dist 函数
 */
class DynamicTreeDiameter {
private:
    struct Node {
        int a, b;      // 该区间特殊点集合的直径端点
        long long d;   // 直径值；a == 0 表示空集合
    };

    int n;                          // 节点个数
    vector<vector<int>> adj;        // 邻接表
    vector<int> depth;              // 节点深度
    vector<int> first, euler;       // 欧拉序：first[u] 为 u 首次出现下标，euler 为欧拉序列
    vector<vector<int>> rmq;        // rmq[k][i]：euler[i..i+2^k-1] 中深度最小节点在 euler 中的下标
    vector<int> lg;                 // log2 预处理
    vector<char> inSet;             // 节点是否在特殊点集合中
    vector<Node> seg;               // 线段树节点
    int SZ;                         // 线段树叶子数量（2 的幂）

    // ----- 迭代 DFS 预处理：深度 + 欧拉序 + first（避免递归栈溢出）-----
    void buildLCA(int root) {
        depth.assign(n + 1, 0);
        first.assign(n + 1, -1);
        euler.clear();

        vector<int> parent(n + 1, 0), it(n + 1, 0), stk;
        stk.push_back(root);
        while (!stk.empty()) {
            int u = stk.back();
            if (first[u] == -1) {              // 第一次进入该节点
                first[u] = (int)euler.size();
                euler.push_back(u);
            }
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                stk.push_back(v);
            } else {                            // 子树访问完毕，回溯到父节点
                stk.pop_back();
                if (!stk.empty()) euler.push_back(stk.back());
            }
        }

        // RMQ 预处理
        int m = (int)euler.size();
        lg.assign(m + 1, 0);
        for (int i = 2; i <= m; ++i) lg[i] = lg[i >> 1] + 1;
        int K = lg[m] + 1;
        rmq.assign(K, vector<int>(m));
        for (int i = 0; i < m; ++i) rmq[0][i] = i;
        for (int k = 1; k < K; ++k) {
            int len = 1 << (k - 1);
            for (int i = 0; i + (1 << k) <= m; ++i) {
                int x = rmq[k - 1][i], y = rmq[k - 1][i + len];
                rmq[k][i] = (depth[euler[x]] <= depth[euler[y]]) ? x : y;
            }
        }
    }

    // ----- O(1) LCA 查询（欧拉序区间 RMQ）-----
    int lca(int u, int v) const {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        int k = lg[r - l + 1];
        int x = rmq[k][l], y = rmq[k][r - (1 << k) + 1];
        return euler[(depth[euler[x]] <= depth[euler[y]]) ? x : y];
    }

    // ----- 树上两点距离 -----
    long long dist(int u, int v) const {
        int w = lca(u, v);
        return (long long)depth[u] + depth[v] - 2LL * depth[w];
    }

    // ----- 合并两个区间的直径信息 -----
    // 依据直径端点引理：并集直径 = max(左直径, 右直径, 左右端点交叉 4 种距离)
    Node merge(const Node& A, const Node& B) const {
        if (A.a == 0) return B;
        if (B.a == 0) return A;
        Node res = (A.d >= B.d) ? A : B;
        auto upd = [&](int x, int y) {
            long long dd = dist(x, y);
            if (dd > res.d) res = {x, y, dd};
        };
        upd(A.a, B.a); upd(A.a, B.b);
        upd(A.b, B.a); upd(A.b, B.b);
        return res;
    }

    // ----- 线段树上拉取：用左右儿子更新当前节点 -----
    void pull(int p) {
        seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
    }

    // ----- 单点修改（pos 为节点编号 1..n）-----
    void pointSet(int pos, Node val) {
        int p = pos + SZ - 1;
        seg[p] = val;
        for (p >>= 1; p; p >>= 1) pull(p);
    }

public:
    // ----- 构造函数 -----
    DynamicTreeDiameter(int n) : n(n) {
        adj.assign(n + 1, {});
        inSet.assign(n + 1, 0);
        SZ = 1;
        while (SZ < n) SZ <<= 1;
        seg.assign(SZ << 1, Node{0, 0, 0});
    }

    // ----- 加边（无向）-----
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ----- 预处理：所有边加完后调用，root 默认为 1 -----
    void build(int root = 1) {
        buildLCA(root);
    }

    // ----- 批量初始化特殊点（自动计算当前直径）-----
    void setInitial(const vector<int>& points) {
        fill(inSet.begin(), inSet.end(), 0);
        fill(seg.begin(), seg.end(), Node{0, 0, 0});
        for (int p : points) {
            inSet[p] = 1;
            seg[SZ + p - 1] = Node{p, p, 0};
        }
        for (int p = SZ - 1; p >= 1; --p) pull(p);
    }

    // ----- 插入一个特殊点（若已存在则忽略）-----
    void insert(int u) {
        if (inSet[u]) return;
        inSet[u] = 1;
        pointSet(u, Node{u, u, 0});
    }

    // ----- 删除一个特殊点（若不存在则忽略）-----
    void erase(int u) {
        if (!inSet[u]) return;
        inSet[u] = 0;
        pointSet(u, Node{0, 0, 0});
    }

    // ----- 切换特殊状态：若为特殊点则删除，否则插入 -----
    void toggle(int u) {
        if (inSet[u]) erase(u);
        else insert(u);
    }

    // ----- 返回任意两点距离（辅助接口）-----
    long long getDist(int u, int v) const {
        return dist(u, v);
    }

    // ----- 获取当前真实直径（空集合返回 0）-----
    long long getDiameter() const {
        return seg[1].d;
    }

    // ----- 获取当前特殊点数量 -----
    int size() const {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += inSet[i];
        return cnt;
    }

    // ----- 判断某点是否为特殊点 -----
    bool isSpecial(int u) const {
        return inSet[u];
    }
};

// ========== 使用示例 ==========
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    DynamicTreeDiameter solver(n);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        solver.addEdge(u, v);
    }
    solver.build();

    int k;
    cin >> k;
    vector<int> init(k);
    for (int i = 0; i < k; ++i) cin >> init[i];
    solver.setInitial(init);

    cout << solver.getDiameter() << '\n';

    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) solver.insert(x);
        else if (op == 2) solver.erase(x);
        else if (op == 3) solver.toggle(x);
        cout << solver.getDiameter() << '\n';
    }

    return 0;
}


/*

---------------------------------------------------------

class DynamicTreeDiameter {
private:
    struct Node {
        int a, b;
        long long d;
    };

    int n;
    vector<vector<int>> adj;
    vector<int> depth, first, euler;
    vector<vector<int>> rmq;
    vector<int> lg;
    vector<char> inSet;
    vector<Node> seg;
    int SZ;

    void buildLCA(int root) {
        depth.assign(n + 1, 0);
        first.assign(n + 1, -1);
        euler.clear();
        vector<int> parent(n + 1, 0), it(n + 1, 0), stk;
        stk.push_back(root);
        while (!stk.empty()) {
            int u = stk.back();
            if (first[u] == -1) {
                first[u] = (int)euler.size();
                euler.push_back(u);
            }
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                stk.push_back(v);
            } else {
                stk.pop_back();
                if (!stk.empty()) euler.push_back(stk.back());
            }
        }
        int m = (int)euler.size();
        lg.assign(m + 1, 0);
        for (int i = 2; i <= m; ++i) lg[i] = lg[i >> 1] + 1;
        int K = lg[m] + 1;
        rmq.assign(K, vector<int>(m));
        for (int i = 0; i < m; ++i) rmq[0][i] = i;
        for (int k = 1; k < K; ++k) {
            int len = 1 << (k - 1);
            for (int i = 0; i + (1 << k) <= m; ++i) {
                int x = rmq[k - 1][i], y = rmq[k - 1][i + len];
                rmq[k][i] = (depth[euler[x]] <= depth[euler[y]]) ? x : y;
            }
        }
    }

    int lca(int u, int v) const {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        int k = lg[r - l + 1];
        int x = rmq[k][l], y = rmq[k][r - (1 << k) + 1];
        return euler[(depth[euler[x]] <= depth[euler[y]]) ? x : y];
    }

    long long dist(int u, int v) const {
        int w = lca(u, v);
        return (long long)depth[u] + depth[v] - 2LL * depth[w];
    }

    Node merge(const Node& A, const Node& B) const {
        if (A.a == 0) return B;
        if (B.a == 0) return A;
        Node res = (A.d >= B.d) ? A : B;
        auto upd = [&](int x, int y) {
            long long dd = dist(x, y);
            if (dd > res.d) res = {x, y, dd};
        };
        upd(A.a, B.a);
        upd(A.a, B.b);
        upd(A.b, B.a);
        upd(A.b, B.b);
        return res;
    }

    void pull(int p) {
        seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
    }

    void pointSet(int pos, Node val) {
        int p = pos + SZ - 1;
        seg[p] = val;
        for (p >>= 1; p; p >>= 1) pull(p);
    }

public:
    DynamicTreeDiameter(int n) : n(n) {
        adj.assign(n + 1, {});
        inSet.assign(n + 1, 0);
        SZ = 1;
        while (SZ < n) SZ <<= 1;
        seg.assign(SZ << 1, Node{0, 0, 0});
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 1) {
        buildLCA(root);
    }

    void setInitial(const vector<int>& points) {
        fill(inSet.begin(), inSet.end(), 0);
        fill(seg.begin(), seg.end(), Node{0, 0, 0});
        for (int p : points) {
            inSet[p] = 1;
            seg[SZ + p - 1] = Node{p, p, 0};
        }
        for (int p = SZ - 1; p >= 1; --p) pull(p);
    }

    void insert(int u) {
        if (inSet[u]) return;
        inSet[u] = 1;
        pointSet(u, Node{u, u, 0});
    }

    void erase(int u) {
        if (!inSet[u]) return;
        inSet[u] = 0;
        pointSet(u, Node{0, 0, 0});
    }

    void toggle(int u) {
        if (inSet[u]) erase(u);
        else insert(u);
    }

    long long getDist(int u, int v) const {
        return dist(u, v);
    }

    long long getDiameter() const {
        return seg[1].d;
    }

    int size() const {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += inSet[i];
        return cnt;
    }

    bool isSpecial(int u) const {
        return inSet[u];
    }
};


-----------------------------------------------------------
*/
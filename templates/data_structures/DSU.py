import sys
sys.setrecursionlimit(1 << 25)   # 提高递归深度（为递归 find 或其它递归操作预留）



# 1-indexed n -> n + 1
class DSU:
    def __init__(self, n):
        self.pa = list(range(n))
        self.sz = [1] * n
        self.num = n
    def find(self, x) -> int:
        rt = x
        while rt != self.pa[rt]:
            rt = self.pa[rt]
        while x != rt:
            self.pa[x], x = rt, self.pa[x]
        return rt
    def unite(self, x, y) -> bool:
        rx, ry = self.find(x), self.find(y)
        if rx == ry: return False
        if self.sz[rx] < self.sz[y]:
            rx, ry = ry, rx
        self.pa[ry] = rx
        self.sz[rx] += self.sz[y]
        self.num -= 1
        return True
    def same(self, x, y) -> bool:
        return self.find(x) == self.find(y)
    def getSize(self, x) -> int:
        return self.sz[self.find(x)]

n = 0
fa = list(range(n + 1))
sz = [1] * (n + 1)
def find(x):
    while x != fa[x]:
        fa[x] = fa[fa[x]]
        x = fa[x]
    return x
def unite(x, y):
    fx, fy = find(x), find(y)
    if fx == fy:
        return False
    if sz[fx] < sz[fy]:
        fx, fy = fy, fx
    fa[fy] = fx
    sz[fx] += sz[fy]
    return True








class DSU_:
    """
    并查集 (Disjoint Set Union)
    - 路径压缩 (非递归实现，安全高效)
    - 按大小合并 (Union by Size)
    - 节点编号: 0 ~ n-1 (若需 1-based，初始化 n+1 并忽略索引 0)
    """
    __slots__ = ('fa', 'sz')

    def __init__(self, n: int):

        self.fa = list(range(n))
        self.sz = [1] * n

    # ---------- 非递归 find (推荐，无递归栈风险) ----------
    def find(self, x: int) -> int:
        fa = self.fa
        while fa[x] != x:
            fa[x] = fa[fa[x]]   # 路径压缩
            x = fa[x]
        return x

    # ---------- 递归 find (备用，若想用可取消注释) ----------
    # def find(self, x: int) -> int:
    #     if self.fa[x] != x:
    #         self.fa[x] = self.find(self.fa[x])
    #     return self.fa[x]

    def unite(self, a: int, b: int) -> bool:
        """
        合并 a 和 b 所在集合
        返回 True 表示合并成功 (原本不在同一集合)
        返回 False 表示已在同一集合
        """
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb:
            return False
        # 按大小合并：小集合挂到大集合
        if self.sz[ra] < self.sz[rb]:
            ra, rb = rb, ra
        self.fa[rb] = ra
        self.sz[ra] += self.sz[rb]
        return True

    def same(self, a: int, b: int) -> bool:
        """判断 a 和 b 是否在同一集合"""
        return self.find(a) == self.find(b)

    def size(self, x: int) -> int:
        """返回 x 所在集合的大小"""
        return self.sz[self.find(x)]

    def count(self) -> int:
        """返回当前连通块数量 (集合个数)"""
        return sum(1 for i in range(len(self.fa)) if self.find(i) == i)

    def roots(self) -> list:
        """返回所有集合的根节点列表"""
        return [i for i in range(len(self.fa)) if self.find(i) == i]

    def reset(self, n: int) -> None:
        """重置为 n 个独立节点"""
        self.fa = list(range(n))
        self.sz = [1] * n


def solve():
    N, M = map(int, sys.stdin.buffer.readline().split())
    dsu = DSU_(N + 1)          # 若节点编号 1..N，则初始化 N+1，忽略下标 0
    redundant = []            # 存储环边 (边编号, u, v)

    for i in range(1, M + 1):
        u, v = map(int, sys.stdin.buffer.readline().split())
        if not dsu.unite(u, v):
            redundant.append((i, u, v))

    # 统计连通块
    comp_cnt = dsu.count() - 1   # 因为包含下标 0，需减 1
    print(f"连通块数量: {comp_cnt}")
    print(f"环边数量: {len(redundant)}")
    print(f"所有环边: {redundant}")

if __name__ == "__main__":
    solve()
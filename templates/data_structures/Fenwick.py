from __future__ import annotations  # 第一行

class Fenwick:
    """
    树状数组 (Binary Indexed Tree / BIT) - 单点修改与区间查询

    【功能特性】
    1. O(N) 线性建树（传入数组时）。
    2. O(log N) 单点增加 add(i, delta)。
    3. O(log N) 前缀和查询 query(i) 与 区间和查询 query_range(l, r)。
    4. O(log N) 倍增查找前缀和阈值 kth(k)（用于权值树状数组求第 k 小，无需二分）。

    【下标说明】
    - 内部严格采用 1-indexed。
    - 若传入初始数组（0-indexed），会自动转为 1-indexed 建树。
    - 查询与修改传入的下标范围为 [1, n]。
    """
    def __init__(self, n_or_arr: int | list[int]) -> None:
        if isinstance(n_or_arr, int):
            self.n: int = n_or_arr
            self.tree: list[int] = [0] * (self.n + 1)
        else:
            self.n: int = len(n_or_arr)
            self.tree = [0] + list(n_or_arr)
            for i in range(1, self.n + 1):
                nxt = i + (i & -i)
                if nxt <= self.n:
                    self.tree[nxt] += self.tree[i]
    def add(self, i: int, delta: int) -> None:
        while i <= self.n:
            self.tree[i] += delta
            i += i & -i
    def query(self, i: int) -> int:
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
    def query_range(self, l: int, r: int) -> int:
        if l > r:
            return 0
        return self.query(r) - self.query(l - 1)
    def kth(self, k: int) -> int:
        if k <= 0:
            return 1
        idx = 0
        step = 1 << (self.n.bit_length() - 1)
        while step > 0:
            nxt = idx + step
            if nxt <= self.n and self.tree[nxt] < k:
                idx = nxt
                k -= self.tree[idx]
            step >>= 1
        return idx + 1

class RangeFenwick:
    """
    树状数组 - 区间修改与区间查询 (差分维护)

    【功能特性】
    1. O(log N) 区间增加 add_range(l, r, delta)。
    2. O(log N) 区间求和 query_range(l, r)。

    【复杂度】
    - 空间复杂度: O(N)
    - 增/查时间复杂度: O(log N)
    """
    def __init__(self, n: int) -> None:
        self.n: int = n
        self.t1: list[int] = [0] * (n + 1)  
        self.t2: list[int] = [0] * (n + 1)  
    def _add(self, i: int, v: int) -> None:
        v_idx = i * v
        while i <= self.n:
            self.t1[i] += v
            self.t2[i] += v_idx
            i += i & -i
    def add_range(self, l: int, r: int, delta: int) -> None:
        self._add(l, delta)
        self._add(r + 1, -delta)
    def _query(self, i: int) -> int:
        s1 = 0
        s2 = 0
        cur = i
        while cur > 0:
            s1 += self.t1[cur]
            s2 += self.t2[cur]
            cur -= cur & -cur
        return (i + 1) * s1 - s2
    def query_range(self, l: int, r: int) -> int:
        if l > r:
            return 0
        return self._query(r) - self._query(l - 1)
class SegmentTree:
    """
    线段树 (Segment Tree) - 区间修改与区间查询 (Lazy 标记版)

    【功能特性】
    1. O(N) 建树。
    2. O(log N) 区间增加：add(l, r, val)。
    3. O(log N) 区间求和：query(l, r)。

    【下标说明】
    - 对外接口一律采用 1-indexed 闭区间 [l, r]。
    - 若传入列表初始化，默认将 0-indexed 映射为 1-indexed。
    """

    def __init__(self, data):
        """
        data 可以是一个整数 n（初始全 0），也可以是一个列表/数组
        """
        if isinstance(data, int):
            self.n = data
            self.tree = [0] * (4 * self.n)
            self.lazy = [0] * (4 * self.n)
        else:
            self.n = len(data)
            self.tree = [0] * (4 * self.n)
            self.lazy = [0] * (4 * self.n)
            self._build(1, 1, self.n, data)
    def _build(self, u, l, r, data):
        if l == r:
            self.tree[u] = data[l - 1]
            return
        mid = (l + r) >> 1
        self._build(u << 1, l, mid, data)
        self._build((u << 1) | 1, mid + 1, r, data)
        self.tree[u] = self.tree[u << 1] + self.tree[(u << 1) | 1]
    def _push_down(self, u, l, r):
        if self.lazy[u] != 0:
            lz = self.lazy[u]
            mid = (l + r) >> 1
            left_len = mid - l + 1
            right_len = r - mid
            # 下传左孩子
            self.lazy[u << 1] += lz
            self.tree[u << 1] += lz * left_len
            # 下传右孩子
            self.lazy[(u << 1) | 1] += lz
            self.tree[(u << 1) | 1] += lz * right_len
            self.lazy[u] = 0
    def add(self, ql, qr, val, u=1, l=1, r=None):
        """区间加：将区间 [ql, qr] 每个数加上 val"""
        if r is None:
            r = self.n
        if ql <= l and r <= qr:
            self.tree[u] += val * (r - l + 1)
            self.lazy[u] += val
            return
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        if ql <= mid:
            self.add(ql, qr, val, u << 1, l, mid)
        if qr > mid:
            self.add(ql, qr, val, (u << 1) | 1, mid + 1, r)
        self.tree[u] = self.tree[u << 1] + self.tree[(u << 1) | 1]
    def query(self, ql, qr, u=1, l=1, r=None):
        """区间求和：查询区间 [ql, qr] 的总和"""
        if r is None:
            r = self.n
        if ql <= l and r <= qr:
            return self.tree[u]
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        res = 0
        if ql <= mid:
            res += self.query(ql, qr, u << 1, l, mid)
        if qr > mid:
            res += self.query(ql, qr, (u << 1) | 1, mid + 1, r)
        return res


class FastSegmentTree:
    """
    非递归线段树 (ZKW Segment Tree) - 单点修改与区间最值/求和
    【功能特性】
    1. O(N) 初始化。
    2. O(log N) 单点修改：update(i, val)。
    3. O(log N) 区间最值查询：query(l, r)。
    4. 纯迭代实现，常数极小，免设递归深度。
    【下标说明】
    - 对外接口采用 1-indexed 闭区间 [l, r]。
    """
    def __init__(self, data, op=max, default=-10**18):
        """
        - data: 数组列表或大小 n
        - op: 结合律函数，默认求最大值 max (求和可用 lambda x, y: x + y)
        - default: 单位元 (求最大值取 -INF，求最小值取 INF，求和取 0)
        """
        self.op = op
        self.default = default
        if isinstance(data, int):
            self.n = data
            self.size = 1 << (self.n + 1).bit_length()
            self.tree = [default] * (2 * self.size)
        else:
            self.n = len(data)
            self.size = 1 << (self.n + 1).bit_length()
            self.tree = [default] * (2 * self.size)
            for i in range(self.n):
                self.tree[self.size + i + 1] = data[i]
            for i in range(self.size - 1, 0, -1):
                self.tree[i] = self.op(self.tree[i << 1], self.tree[(i << 1) | 1])
    def update(self, i, val):
        """单点修改：a[i] = val (1-indexed)"""
        pos = self.size + i
        self.tree[pos] = val
        pos >>= 1
        while pos > 0:
            self.tree[pos] = self.op(self.tree[pos << 1], self.tree[(pos << 1) | 1])
            pos >>= 1
    def query(self, l, r):
        """区间查询：op(a[l ... r]) (1-indexed 闭区间)"""
        res_l = self.default
        res_r = self.default
        l += self.size
        r += self.size
        while l <= r:
            if l & 1:
                res_l = self.op(res_l, self.tree[l])
                l += 1
            if not (r & 1):
                res_r = self.op(self.tree[r], res_r)
                r -= 1
            l >>= 1
            r >>= 1
        return self.op(res_l, res_r)


"""

class UniversalSegTree:
    def __init__(self, data: int | list, op, e, mapping=None, composition=None):
        self.op = op
        self.e = e
        self.mapping = mapping
        self.composition = composition
        if isinstance(data, int):
            self.n = data
            self.tree = [self.e] * (4 * self.n)
            self.lazy = [None] * (4 * self.n)
        else:
            self.n = len(data)
            self.tree = [self.e] * (4 * self.n)
            self.lazy = [None] * (4 * self.n)
            self._build(1, 1, self.n, data)
    def _build(self, u: int, l: int, r: int, data: list):
        if l == r:
            self.tree[u] = data[l - 1]
            return
        mid = (l + r) >> 1
        self._build(u << 1, l, mid, data)
        self._build((u << 1) | 1, mid + 1, r, data)
        self.tree[u] = self.op(self.tree[u << 1], self.tree[(u << 1) | 1])
    def _apply(self, u: int, l: int, r: int, tag):
        if self.mapping is None:
            return
        self.tree[u] = self.mapping(tag, self.tree[u], r - l + 1)
        if l != r:
            if self.lazy[u] is None:
                self.lazy[u] = tag
            else:
                self.lazy[u] = self.composition(tag, self.lazy[u])
    def _push_down(self, u: int, l: int, r: int):
        if self.lazy[u] is not None:
            mid = (l + r) >> 1
            self._apply(u << 1, l, mid, self.lazy[u])
            self._apply((u << 1) | 1, mid + 1, r, self.lazy[u])
            self.lazy[u] = None
    def update(self, ql: int, qr: int, tag, u: int = 1, l: int = 1, r: int | None = None):
        if r is None:
            r = self.n
        if ql <= l and r <= qr:
            self._apply(u, l, r, tag)
            return
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        if ql <= mid:
            self.update(ql, qr, tag, u << 1, l, mid)
        if qr > mid:
            self.update(ql, qr, tag, (u << 1) | 1, mid + 1, r)
        self.tree[u] = self.op(self.tree[u << 1], self.tree[(u << 1) | 1])
    def set(self, pos: int, val, u: int = 1, l: int = 1, r: int | None = None):
        if r is None:
            r = self.n
        if l == r:
            self.tree[u] = val
            self.lazy[u] = None
            return
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        if pos <= mid:
            self.set(pos, val, u << 1, l, mid)
        else:
            self.set(pos, val, (u << 1) | 1, mid + 1, r)
        self.tree[u] = self.op(self.tree[u << 1], self.tree[(u << 1) | 1])
    def query(self, ql: int, qr: int, u: int = 1, l: int = 1, r: int | None = None):
        if r is None:
            r = self.n
        if ql <= l and r <= qr:
            return self.tree[u]
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        res = self.e
        if ql <= mid:
            res = self.op(res, self.query(ql, qr, u << 1, l, mid))
        if qr > mid:
            res = self.op(res, self.query(ql, qr, (u << 1) | 1, mid + 1, r))
        return res
    @classmethod
    def range_add_sum(cls, data: int | list) -> UniversalSegTree:
        return cls(data, op=lambda a, b: a + b, e=0,
                   mapping=lambda t, v, sz: v + t * sz,
                   composition=lambda new_t, old_t: old_t + new_t)
    @classmethod
    def range_add_max(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        return cls(data, op=max, e=-inf,
                   mapping=lambda t, v, sz: v + t,
                   composition=lambda new_t, old_t: old_t + new_t)
    @classmethod
    def range_add_min(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        return cls(data, op=min, e=inf,
                   mapping=lambda t, v, sz: v + t,
                   composition=lambda new_t, old_t: old_t + new_t)
    @classmethod
    def range_set_sum(cls, data: int | list) -> UniversalSegTree:
        return cls(data, op=lambda a, b: a + b, e=0,
                   mapping=lambda t, v, sz: t * sz,
                   composition=lambda new_t, old_t: new_t)
    @classmethod
    def range_set_min(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        return cls(data, op=min, e=inf,
                   mapping=lambda t, v, sz: t,
                   composition=lambda new_t, old_t: new_t)
    @classmethod
    def range_set_max(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        return cls(data, op=max, e=-inf,
                   mapping=lambda t, v, sz: t,
                   composition=lambda new_t, old_t: new_t)
    @classmethod
    def point_gcd(cls, data: int | list) -> UniversalSegTree:
        return cls(data, op=gcd, e=0)

"""

from __future__ import annotations

import math


class UniversalSegTree:
    """
    通用泛型线段树 (ACL 风格 Lazy 线段树)

    【设计原理】
    将线段树的底层维护逻辑抽象为代数结构，彻底解耦树形结构的递归与具体的业务运算。
    用户只需关注以下 4 个核心要素，即可组合出任意区间操作：
    1. op(a, b): 结合律区间合并函数，用于左右子节点聚合向上更新（push_up）。
    2. e: op 运算的单位元，满足 op(x, e) == op(e, x) == x。
       - 求和: 0
       - 最大值: -INF
       - 最小值: INF
       - 最大公约数 GCD: 0
       - 异或和: 0
    3. mapping(tag, val, sz): 懒标记作用函数。定义将一个懒标记 tag 应用在
       区间长度为 sz、原有聚合值为 val 的节点上时，节点的新聚合值。
       - 区间加求和: mapping(tag, val, sz) = val + tag * sz
       - 区间加求最值: mapping(tag, val, sz) = val + tag
       - 区间覆盖求和: mapping(tag, val, sz) = tag * sz
       - 区间覆盖求最值: mapping(tag, val, sz) = tag
    4. composition(new_tag, old_tag): 懒标记复合函数。定义在已有历史标记 old_tag 的
       节点上，再打上一个新的标记 new_tag 时，合成后的新标记。
       - 区间累加: old_tag + new_tag
       - 区间覆盖: new_tag (新覆盖直接顶替旧标记)

    【下标约定与映射】
    - 对外查询与修改接口（update, set, query）均严格采用 1-indexed 闭区间 [l, r]。
    - 传入列表 data 进行初始化时，输入为标准 Python 0-indexed 列表，内部自动映射：
      data[0] 对应线段树位置 1，data[n - 1] 对应线段树位置 n。
    - 传入整数 n 进行初始化时，生成长度为 n、初始值全为单位元 e 的线段树。

    【复杂度】
    - 建树时间复杂度: O(N)
    - 单点修改 / 区间修改 / 区间查询时间复杂度: 严格 O(log N)
    - 空间复杂度: 4N (数组模拟二叉树)
    """

    def __init__(self, data: int | list, op, e, mapping=None, composition=None):
        """
        初始化线段树

        :param data: 整数 n（建立长度为 n 的树）或初始数据列表 list
        :param op: 结合律合并函数，接收两个区间聚合值，返回合并值
        :param e: 结合律运算单位元
        :param mapping: 懒标记应用函数 (tag, val, size) -> new_val，纯单点修改可为 None
        :param composition: 懒标记复合函数 (new_tag, old_tag) -> combined_tag，纯单点修改可为 None
        """
        self.op = op
        self.e = e
        self.mapping = mapping
        self.composition = composition

        if isinstance(data, int):
            self.n = data
            self.tree = [self.e] * (4 * self.n)
            self.lazy = [None] * (4 * self.n)
        else:
            self.n = len(data)
            self.tree = [self.e] * (4 * self.n)
            self.lazy = [None] * (4 * self.n)
            self._build(1, 1, self.n, data)

    def _build(self, u: int, l: int, r: int, data: list):
        if l == r:
            self.tree[u] = data[l - 1]
            return
        mid = (l + r) >> 1
        self._build(u << 1, l, mid, data)
        self._build((u << 1) | 1, mid + 1, r, data)
        self.tree[u] = self.op(self.tree[u << 1], self.tree[(u << 1) | 1])

    def _apply(self, u: int, l: int, r: int, tag):
        """在节点 u 上施加标记 tag"""
        if self.mapping is None:
            return
        self.tree[u] = self.mapping(tag, self.tree[u], r - l + 1)
        if l != r:
            if self.lazy[u] is None:
                self.lazy[u] = tag
            else:
                self.lazy[u] = self.composition(tag, self.lazy[u])

    def _push_down(self, u: int, l: int, r: int):
        """下传懒标记至左右子节点"""
        if self.lazy[u] is not None:
            mid = (l + r) >> 1
            self._apply(u << 1, l, mid, self.lazy[u])
            self._apply((u << 1) | 1, mid + 1, r, self.lazy[u])
            self.lazy[u] = None

    def update(self, ql: int, qr: int, tag, u: int = 1, l: int = 1, r: int | None = None):
        """
        区间修改：在区间 [ql, qr] 上施加懒标记 tag (1 <= ql <= qr <= n)
        - 适用于区间加、区间覆盖赋值等操作
        """
        if r is None:
            r = self.n
        if ql <= l and r <= qr:
            self._apply(u, l, r, tag)
            return
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        if ql <= mid:
            self.update(ql, qr, tag, u << 1, l, mid)
        if qr > mid:
            self.update(ql, qr, tag, (u << 1) | 1, mid + 1, r)
        self.tree[u] = self.op(self.tree[u << 1], self.tree[(u << 1) | 1])

    def set(self, pos: int, val, u: int = 1, l: int = 1, r: int | None = None):
        """
        单点修改：直接将下标 pos 的位置重置为 val (1 <= pos <= n)
        - 适用于单点修改求区间最值/GCD/异或和，或清空某位置历史值
        """
        if r is None:
            r = self.n
        if l == r:
            self.tree[u] = val
            self.lazy[u] = None
            return
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        if pos <= mid:
            self.set(pos, val, u << 1, l, mid)
        else:
            self.set(pos, val, (u << 1) | 1, mid + 1, r)
        self.tree[u] = self.op(self.tree[u << 1], self.tree[(u << 1) | 1])

    def query(self, ql: int, qr: int, u: int = 1, l: int = 1, r: int | None = None):
        """
        区间查询：查询闭区间 [ql, qr] 经过 op 合并后的聚合值 (1 <= ql <= qr <= n)
        """
        if r is None:
            r = self.n
        if ql <= l and r <= qr:
            return self.tree[u]
        self._push_down(u, l, r)
        mid = (l + r) >> 1
        res = self.e
        if ql <= mid:
            res = self.op(res, self.query(ql, qr, u << 1, l, mid))
        if qr > mid:
            res = self.op(res, self.query(ql, qr, (u << 1) | 1, mid + 1, r))
        return res

    # ---------------- 常用业务场景预置快捷工厂方法 ----------------

    @classmethod
    def range_add_sum(cls, data: int | list) -> UniversalSegTree:
        """区间加 + 区间求和"""
        return cls(data, op=lambda a, b: a + b, e=0,
                   mapping=lambda t, v, sz: v + t * sz,
                   composition=lambda new_t, old_t: old_t + new_t)

    @classmethod
    def range_add_max(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        """区间加 + 区间最大值"""
        return cls(data, op=max, e=-inf,
                   mapping=lambda t, v, sz: v + t,
                   composition=lambda new_t, old_t: old_t + new_t)

    @classmethod
    def range_add_min(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        """区间加 + 区间最小值"""
        return cls(data, op=min, e=inf,
                   mapping=lambda t, v, sz: v + t,
                   composition=lambda new_t, old_t: old_t + new_t)

    @classmethod
    def range_set_sum(cls, data: int | list) -> UniversalSegTree:
        """区间覆盖 (重置赋值) + 区间求和"""
        return cls(data, op=lambda a, b: a + b, e=0,
                   mapping=lambda t, v, sz: t * sz,
                   composition=lambda new_t, old_t: new_t)

    @classmethod
    def range_set_min(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        """区间覆盖 (重置赋值) + 区间最小值"""
        return cls(data, op=min, e=inf,
                   mapping=lambda t, v, sz: t,
                   composition=lambda new_t, old_t: new_t)

    @classmethod
    def range_set_max(cls, data: int | list, inf: int = 10**18) -> UniversalSegTree:
        """区间覆盖 (重置赋值) + 区间最大值"""
        return cls(data, op=max, e=-inf,
                   mapping=lambda t, v, sz: t,
                   composition=lambda new_t, old_t: new_t)

    @classmethod
    def point_gcd(cls, data: int | list) -> UniversalSegTree:
        """单点修改 + 区间最大公约数 GCD (无需懒标记)"""
        return cls(data, op=math.gcd, e=0)

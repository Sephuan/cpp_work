# from __future__ import annotations
import sys
import builtins
from collections import *
from bisect import *
from math import *
from heapq import *
from functools import lru_cache
from itertools import *
from random import *
input = sys.stdin.readline
write = sys.stdout.write
II = lambda : int(input().strip())
I = lambda : input().strip()
def MI(e = int): return map(e, input().split())
def LMI(e = int): return list(map(e, input().split()))
def MAT(n, e = int): return [list(map(e, input().split())) for _ in range(n)]
def CMAT(n): return [list(input().strip()) for _ in range(n)]
pow = builtins.pow
# sys.setrecursionlimit(1 << 20)

INF = 10**18
MOD, mod = 998_244_353, 10**9+7


# it = iter(sys.stdin.read().split())

class Fenwick:
    def __init__(self, n_or_arr) -> None:
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

def sol():
    out = []
    n, m = MI()
    edges = []
    for i in range(n - 1):
        u, v = MI()
        a, b = min(u, v), max(u, v)
        edges.append((a, b))
    edges.sort(lambda x: -x[0])
    qry = []
    for i in range(m):
        c, l, r = MI()
        qry.append((c, l, r, i))
    qry.sort(lambda x: -x[1])
    fw = Fenwick(n)
    ans = [0] * m
    p = 0
    for c, l, r, i in qry:
        while p < n - 1 and edges[p][0] >= l:
            fw.add(edges[p][1], 1)
            p += 1
        ans[i] = r - l + 1 - fw.query(r) - (l <= c <= r)
    write('\n'.join(map(str, ans)))

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
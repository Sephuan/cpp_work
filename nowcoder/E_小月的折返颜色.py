# from __future__ import annotations
import sys
import builtins
from collections import *
from bisect import *
from math import *
from heapq import *
from functools import lru_cache
from itertools import *
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
        if self.sz[rx] < self.sz[ry]:
            rx, ry = ry, rx
        self.pa[ry] = rx
        self.sz[rx] += self.sz[ry]
        self.num -= 1
        return True
    def same(self, x, y) -> bool:
        return self.find(x) == self.find(y)
    def getSize(self, x) -> int:
        return self.sz[self.find(x)]

# it = iter(sys.stdin.read().split())

def sol():
    out = []
    n = II()
    c = [0] + LMI()
    dsu = DSU(n + 1)
    d = defaultdict(list)
    vec = []
    for i in range(1, n):
        u, v = MI()
        if c[u] == c[v]:
            dsu.unite(u, v)
        else:
            vec.append((u, v))
    for u, v in vec:
        u = dsu.find(u)
        v = dsu.find(v)
        d[u].append(v)
        d[v].append(u)
    ans = 0
    for i, vec in d.items():
        vec.sort(key=lambda x: c[x])
        # print(i, d, vec)
        j = 0
        m = len(vec)
        while j < m:
            ssz = dsu.sz[vec[j]]
            sqr = dsu.sz[vec[j]] ** 2
            k = j + 1
            while k < m and c[vec[k]] == c[vec[j]]:
                ssz += dsu.sz[vec[k]]
                sqr += dsu.sz[vec[k]] ** 2
                k += 1
            ans += ssz ** 2 - sqr >> 1
            j = k
    print(ans)

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
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
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            try:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    to = stack[-1].send(to)
            except StopIteration as e:
                stack.pop()
                if not stack:
                    return e.value
                to = e.value
    return wrappedfunc


INF = 10**18
MOD, mod = 998_244_353, 10**9+7


# it = iter(sys.stdin.read().split())

out = []
def sol():
    n = II()
    c = [0] + LMI()
    adj = [[] for _ in range(n + 1)]
    inic = 0
    dp = [0] * (n + 1)
    val = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = MI()
        adj[u].append(v)
        adj[v].append(u)
        if c[u] != c[v]:
            inic += 1
            val[u] -= 1
            val[v] -= 1
        else:
            val[u] += 1
            val[v] += 1
    maxg = 0
    @bootstrap
    def dfs(u, p):
        nonlocal maxg
        sub = g1 = g2 = 0
        for v in adj[u]:
            if v != p:
                w = 1 if c[u] == c[v] else -1 
                yield dfs(v, u)
                sub = dp[v] - 2 * w
                if sub > g1:
                    g2, g1 = g1, sub
                elif sub > g2:
                    g2 = sub
        maxg = max(maxg, val[u] + g1 + g2)
        dp[u] = val[u] + g1
    dfs(1, 0)
    print(inic + maxg)

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
    # write('\n'.join(map(str, out)))
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


def sol():
    out = []
    n = II()
    a = LMI()
    p = [0] * (n + 1)
    for i, v in enumerate(a, 1):
        if i & 1:
            p[v] = 1
    l, r = 1, n
    cnt = 1
    while l < r:
        if l & 1 != p[cnt] and r & 1 != p[cnt]:
            print('NO')
            return
        if l & 1 == p[cnt]:
            l += 1
        elif r & 1 == p[cnt]:
            r -= 1
        cnt += 1
    print('YES')

if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
        # write('\n')
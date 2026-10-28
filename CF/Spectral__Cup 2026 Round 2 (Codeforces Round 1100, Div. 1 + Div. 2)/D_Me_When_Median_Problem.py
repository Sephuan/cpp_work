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

def sol():
    out = []
    n = II()
    a = LMI()
    b = LMI()
    def chk(x):
        c = [0] * n
        for i in range(n):
            c[i] = (a[i] >= x) + (b[i] >= x)
        p = 0
        cz = 0
        c2 = sum(1 for i in c if i == 2)
        while p < n:
            while p < n and c[p] != 0:
                p += 1
            if p < n:
                cz += 1
                while p < n and c[p] < 2:
                    p += 1
        return cz < c2
    l, r = 1, 2 * 10 ** 5
    ans = 0
    while l <= r:
        mid = l + r >> 1
        if chk(mid):
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)

if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
    # write('\n'.join(map(str, out)))
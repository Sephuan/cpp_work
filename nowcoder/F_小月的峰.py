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


# it = iter(sys.stdin.read().split())

def sol():
    out = []
    n = II()
    vec = []
    for i in range(n):
        l, r = MI()
        vec.append((l, r))
    i, j = 1, 2 * 10 ** 9
    ans = INF
    while i <= j:
        d = i + j >> 1
        b11 = [0] * n
        b12 = [0] * n
        b21 = [0] * n
        b22 = [0] * n
        k1, k2 = 1, n - 2
        b11[0], b12[0] = vec[0]
        b21[-1], b22[-1] = vec[-1]
        while k1 < n:
            b11[k1] = max(b11[k1 - 1] + 1, vec[k1][0])
            b12[k1] = min(b12[k1 - 1] + d, vec[k1][1])
            if b11[k1] > b12[k1]:
                break
            k1 += 1
        while k2 >= 0:
            b21[k2] = max(b21[k2 + 1] + 1, vec[k2][0])
            b22[k2] = min(b22[k2 + 1] + d, vec[k2][1])
            if b21[k2] > b22[k2]:
                break
            k2 -= 1
        ok = 0
        for k in range(max(k2 + 1, 1), min(k1, n - 1)):
            if max(b11[k], b21[k], vec[k][0]) <= min(b12[k], b22[k], vec[k][1]):
                ok = 1
                break
        if ok:
            ans = min(ans, d)
            j = d - 1
        else:
            i = d + 1
    print(ans if ans != INF else -1)

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
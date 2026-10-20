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
    n, s = MI()
    a = LMI()
    b = LMI()
    ldp = [[INF] * (n + 3) for i in range(n + 3)]
    rdp = [[INF] * (n + 3) for i in range(n + 3)]
    for i in range(n + 3):
        ldp[i][0] = 0
        rdp[i][0] = 0
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            if i > 1:
                ldp[i][j] = min(ldp[i - 1][j], ldp[i - 2][j - 1] + a[i - 1])
            else:
                ldp[i][j] = min(ldp[i - 1][j], a[i - 1])
    for i in range(n, 0, -1):
        for j in range(1, n - i + 2):
            rdp[i][j] = min(rdp[i + 1][j], rdp[i + 2][j - 1] + b[i - 1])
    def chk(k):
        ok = 0
        for i in range(k, n - k):
            if ldp[i][k] + rdp[i + 2][k] <= s:
                ok = 1
                break
        if ok:
            return True
        return False
    lo, hi = 0, (n >> 2) + 1
    ans = 0
    # print(ldp)
    # print(rdp)
    while lo <= hi:
        mid = lo + hi >> 1
        if chk(mid):
            lo = mid + 1
            ans = mid
        else:
            hi = mid - 1
    print(ans)
    
if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
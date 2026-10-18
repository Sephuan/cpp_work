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
    N = II()
    def chk(a, k, d):
        pro = 1
        for i in range(k):
            pro *= a + i * d
            if pro > N:
                return False
        return True
    ans = 0
    for k in range(3, 20):
        for a in range(1, 1_000_000):
            lo, hi = 1, 10 ** 9
            d = 0
            while lo <= hi:
                mid = lo + hi >> 1
                if chk(a, k, mid):
                    lo = mid + 1
                    d = max(d, mid)
                else:
                    hi = mid - 1
            if d:
                ans += d
            else:
                break
    print(ans)    
if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
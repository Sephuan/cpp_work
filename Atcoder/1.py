# from __future__ import annotations
import sys
import builtins
from collections import *
from bisect import *
from math import *
from heapq import *
from functools import lru_cache
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
    n, k = MI()
    a, b = LMI(), LMI()
    a.sort()
    b.sort()
    ans = min(a[n - k + i] + b[n - 1 - i] for i in range(k))
    print(ans)
    # write('\n'.join(out) + '\n')

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
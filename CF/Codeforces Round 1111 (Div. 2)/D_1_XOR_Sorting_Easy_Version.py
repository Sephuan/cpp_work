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

out = []
it = iter(sys.stdin.read().split())
def sol():
    n, q = int(next(it)), int(next(it))
    a = [int(next(it)) for _ in range(n)]
    p = sorted(range(n), key = a.__getitem__)
    # print(p)
    mx = 0
    for i in range(n):
        mx = max(mx, (i ^ p[i]))
    ans = (1 << (mx.bit_length() - 1)) if mx else 0
    out.append(ans)

if __name__ == '__main__':
    T = 1
    # T = II()
    T = int(next(it))
    for _ in range(T):
        sol()
    write('\n'.join(map(str, out)))
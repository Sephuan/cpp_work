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


it = iter(sys.stdin.read().split())

def sol():
    out = []
    n, q = int(next(it)), int(next(it))
    rt = {}
    for i in range(1, n + 1):
        s, c = next(it), int(next(it))
        cur = rt
        for ch in s:
            if ch not in cur:
                cur[ch] = {}
            cur = cur[ch]
        cur['#'] = [c, i]
    for _ in range(q):
        t = next(it)
        cur = rt
        bm = None
        for ch in t:
            if ch not in cur:
                break
            cur = cur[ch]
            if '#' in cur and cur['#'][0] > 0:
                bm = cur['#']
        if bm is not None:
            bm[0] -= 1
            out.append(str(bm[1]))
        else:
            out.append('0')
    
    write('\n'.join(out) + '\n')

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
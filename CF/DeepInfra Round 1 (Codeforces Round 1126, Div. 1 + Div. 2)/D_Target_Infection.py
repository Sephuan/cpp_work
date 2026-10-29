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
    n, m, k = MI()
    seg = []
    for _ in range(n):
        l, r = MI()
        seg.append((l, r))
    if k == 0:
        write(str(seg[-1][1] + 1) + '\n')
        return
    events = {}
    def add_event(x, d):
        events[x] = events.get(x, 0) + d
    for l, r in seg:
        add_event(l - m, 1)
        add_event(r - m + 1, -1)
        add_event(l, -1)
        add_event(r + 1, 1)
    pts = sorted(events.keys())
    cur_f = 0
    cur_slope = events[pts[0]]
    prev_x = pts[0]
    ans = -1
    for x in pts[1:]:
        if cur_slope == 1:
            s = prev_x + k - cur_f
            if prev_x <= s <= x and s >= 1:
                ans = s
                break
        elif cur_slope == -1:
            s = prev_x + cur_f - k
            if prev_x <= s <= x and s >= 1:
                ans = s
                break
        elif cur_slope == 0:
            if cur_f == k:
                s = max(1, prev_x)
                if s <= x:
                    ans = s
                    break
        cur_f += cur_slope * (x - prev_x)
        cur_slope += events[x]
        prev_x = x
    write(str(ans) + '\n')

if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
    # write('\n'.join(map(str, out)))
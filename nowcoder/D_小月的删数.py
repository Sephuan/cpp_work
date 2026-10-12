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
    a = [0] + LMI()
    pre = [0] * (n + 1)
    for i in range(1, n + 1):
        if i & 1:
            pre[i] = pre[i - 1] + a[i]
        else:
            pre[i] = pre[i - 1] - a[i]
    d = defaultdict(list)
    for i in range(1, n + 1):
        d[a[i]].append(i)
    # print(d)
    ans = INF
    for i, vec in d.items():
        lst = 0
        sum = 0
        cnt = 1
        for v in vec:
            if cnt & 1:
                sum += pre[v - 1] - pre[lst]
            else:
                sum -= pre[v - 1] - pre[lst]
            cnt += 1
            lst = v
        if cnt & 1:
            sum += pre[n] - pre[lst]
        else:
            sum -= pre[n] - pre[lst]
        ans = min(ans, abs(sum))
    print(ans)

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
        # write('\n')
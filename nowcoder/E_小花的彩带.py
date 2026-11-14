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
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            try:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    to = stack[-1].send(to)
            except StopIteration as e:
                stack.pop()
                if not stack:
                    return e.value
                to = e.value
    return wrappedfunc


INF = 10**18
MOD, mod = 998_244_353, 10**9+7
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            try:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    to = stack[-1].send(to)
            except StopIteration as e:
                stack.pop()
                if not stack:
                    return e.value
                to = e.value
    return wrappedfunc

# it = iter(sys.stdin.read().split())

def sol():
    n, L, R = MI()
    s = I()
    dp0 = [0] * (n + 1)
    dp1 = [0] * (n + 1)
    lst0 = lst1 = 0
    pre0 = [0] * (n + 1)
    pre1 = [0] * (n + 1)
    dp0[0] = dp1[0] = pre0[0] = pre1[0] = 1 
    def qry(pre, l, r):
        if l > r:
            return 0
        if l == 0:
            return pre[r]
        return pre[r] - pre[l - 1]
    for i in range(1, n + 1):
        if s[i - 1] == '1' or s[i - 1] == '?':
            dp1[i] += qry(pre0, max(0, lst0, i - R), i - L)
            dp1[i] %= MOD
        if s[i - 1] == '0' or s[i - 1] == '?':
            dp0[i] += qry(pre1, max(0, lst1, i - R), i - L)
            dp0[i] %= MOD
        if s[i - 1] == '1':
            lst1 = i
        if s[i - 1] == '0':
            lst0 = i
        pre0[i] = (pre0[i - 1] + dp0[i]) % MOD
        pre1[i] = (pre1[i - 1] + dp1[i]) % MOD
    print((dp0[n] + dp1[n]) % MOD)

if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
        # write('\n')
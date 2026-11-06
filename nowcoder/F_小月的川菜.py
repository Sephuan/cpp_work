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
sys.setrecursionlimit(1 << 25)

INF = 10**18
MOD, mod = 998_244_353, 10**9+7


# it = iter(sys.stdin.read().split())

class MI:
    MOD = mod
    __slots__ = ('x',)
    def __init__(self, x=0):
        self.x = x % self.MOD
    def __add__(self, o):
        return MI(self.x + (o.x if isinstance(o, MI) else o))
    def __radd__(self, o):
        return MI(o + self.x)
    def __sub__(self, o):
        return MI(self.x - (o.x if isinstance(o, MI) else o))
    def __rsub__(self, o):
        return MI(o - self.x)
    def __mul__(self, o):
        return MI(self.x * (o.x if isinstance(o, MI) else o))
    def __rmul__(self, o):
        return MI(o * self.x)
    def __truediv__(self, o):
        if isinstance(o, MI):
            return MI(self.x * o.inv().x)
        return MI(self.x * pow(o % self.MOD, self.MOD - 2, self.MOD))
    def __pow__(self, e):
        return MI(pow(self.x, e, self.MOD))
    def inv(self):
        return MI(pow(self.x, self.MOD - 2, self.MOD))
    def __int__(self):
        return self.x
    def __eq__(self, o):
        return self.x == (o.x if isinstance(o, MI) else o % self.MOD)
    def __repr__(self):
        return str(self.x)

def sol():
    out = []
    n = II()
    a = [0] + LMI()
    a.sort()
    dp = [[MI(0)] * (n + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] =  1
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            s = a[i] - (j - 1)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * max(0, s)
    print(dp[n][n - 2] * 2 - (n - 1) * dp[n][n - 1] + n * (n - 1) // 2 * dp[n][n])
    
if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
        # write('\n')
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

def eulerSieve(n) -> tuple[list[int], list[int]]:
    min_prime = [0] * (n + 1)
    primes = []
    for i in range(2, n + 1):
        if min_prime[i] == 0:
            min_prime[i] = i
            primes.append(i)
        for p in primes:
            if p * i > n:
                break
            min_prime[p * i] = p
            if i % p == 0:
                break         
    return primes, min_prime

def getFactors(x, min_prime):
    factors = []
    while x > 1:
        p = min_prime[x]
        cnt = 0
        while x % p == 0:
            x //= p
            cnt += 1
        factors.append((p, cnt))
    return factors

_, mp = eulerSieve(1_000_005)

def sol():
    out = []
    n = II()
    facs = getFactors(n, mp)
    maxc = 0
    # print(facs)
    maxc = sum(v for p, v in facs) - 1
    print(maxc + len(facs))

if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
    # write('\n'.join(map(str, out)))
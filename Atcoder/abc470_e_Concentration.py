import sys
from functools import cache

sys.setrecursionlimit(1 << 25)

def sol():
    N, L = map(int, input().split())
    A = list(map(int, input().split()))
    sumA = sum(A)
    @cache
    def dfs(s, m, life):
        if life == 0:
            return 0.0
        if s == 0 and m == 0:
            return 0.0
        unseen = s + 2 * m
        val = 0.0
        if s > 0:
            val += s / unseen * (1.0 + dfs(s - 1, m, life))
        if m > 0:
            rem = unseen - 1
            inner = 0.0
            inner += 1.0 / rem * (1.0 + dfs(s, m - 1, life))
            if s > 0:
                gain = 1.0 if life >= 2 else 0.0
                inner += s / rem * (gain + dfs(s, m - 1, life - 1))
            if m >= 2:
                inner += (2 * m - 2) / rem * dfs(s + 2, m - 2, life - 1)
            val += (2 * m) / unseen * inner
        return val
    expPairs = dfs(0, N, L)
    ans = expPairs * (sumA / N)
    print(f"{ans:.10f}")

if __name__ == "__main__":
    sol()
import sys
from collections import *

def solve():
    d = sys.stdin.buffer.read().split()
    N, K = int(d[0]), int(d[1])
    S = d[2].decode()
    P = [0] * (N + 1)
    for i, ch in enumerate(S, 1):
        P[i] = P[i - 1] + (1 if ch == 'o' else 0)
    def chk(X):
        ptr = -1
        min_v = float('inf')
        for r in range(1, N + 1):
            while (ptr + 1 < r) and (P[ptr + 1] <= P[r] - K):
                ptr += 1
                v_new = P[ptr] - X * ptr
                if v_new < min_v:
                    min_v = v_new
            v_r = P[r] - X * r
            if min_v <= v_r:
                return True
        return False
    lo, hi = 0.0, 1.0
    for _ in range(50):
        mid = (lo + hi) / 2.0
        if chk(mid):
            lo = mid
        else:
            hi = mid
    print("{:.12f}".format(lo))

if __name__ == '__main__':
    solve()
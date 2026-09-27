import sys
from collections import *
from bisect import *
from math import *
from heapq import *
input = sys.stdin.readline
II = lambda : int(input().strip())
I = lambda : input().strip()
def MI(e = int): return map(e, input().split())
def LMI(e = int): return list(map(e, input().split()))
def MAT(n, e = int): return [list(map(e, input().split())) for _ in range(n)]
def CMAT(n): return [list(input().strip()) for _ in range(n)]

INF = 10**18

def sol():
    out = []
    N, Q = MI()
    A = [0] + LMI()
    B = [0] + LMI()
    dis = [INF] * (N + 2)
    dis[N + 1] = 0
    pq = []
    preSum = [0] * (N + 1)
    for i in range(1, N + 1):
        preSum[i] = preSum[i - 1] + A[i]
    for i in range(1, N + 1):
        pq.append((B[i], i))
        dis[i] = B[i]
    heapify(pq)
    while pq:
        d, u = heappop(pq)
        if d > dis[u]:
            continue
        pre = (u - 1 + N - 1) % N + 1
        bac = u % N + 1
        if dis[u] + A[pre] < dis[pre]:
            dis[pre] = dis[u] + A[pre]
            heappush(pq, (dis[pre], pre))
        if dis[u] + A[u] < dis[bac]:
            dis[bac] = dis[u] + A[u]
            heappush(pq, (dis[bac], bac))
    for _ in range(Q):
        S, T = MI()
        if S > T:
            S, T = T, S
        if T == N + 1:
            out.append(str(dis[S]))
        else:
            out.append(str(min(
                dis[S] + dis[T], 
                preSum[T - 1] - preSum[S - 1], 
                preSum[N] - (preSum[T - 1] - preSum[S - 1])
            )))

    sys.stdout.write('\n'.join(out))

if __name__ == '__main__':
    T = 1
    # T = II()
    for _ in range(T):
        sol()
import sys
from heapq import *

def solve():
    data = sys.stdin.buffer.read().split()
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    s = int(next(it))
    
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(next(it))
        v = int(next(it))
        w = int(next(it))
        adj[u].append((v, w))

    INF = 10 ** 18

    dist = [INF] * (n + 1)
    dist[s] = 0
    pq = [(0, s)]

    while pq:
        d, u = heappop(pq)
        if d > dist[u]: continue
        for v, w in adj[u]:
            n_dist = d + w
            if n_dist < dist[v]:
                dist[v] = n_dist
                heappush(pq, (n_dist, v))

    ans = []
    for i in range(1, n + 1):
        if dist[i] == INF:
            ans.append("-1")
        else:
            ans.append(str(dist[i]))
    sys.stdout.write(" ".join(ans))

if __name__ == '__main__':
    solve()
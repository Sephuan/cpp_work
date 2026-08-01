import sys
input = sys.stdin.buffer.readline

class DSU:
    __slots__ = ('fa', )
    def __init__(self, n):
        self.fa = list(range(n + 1))
    def find(self, x):
        fa = self.fa
        while fa[x] != x:
            fa[x] = fa[fa[x]]
            x = fa[x]
        return x
    def unite(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb:
            return False
        self.fa[rb] = ra
        return True

def solve():
    N, M = map(int, input().split())
    dsu = DSU(N)
    red = []
    for i in range(1, M + 1):
        A, B = map(int, input().split())
        if not dsu.unite(A, B):
            red.append((i, A))

    rts = [i for i in range(1, N + 1) if dsu.find(i) == i]
    k = len(rts)
    out = [str(k - 1)]
    idx = 0
    for i in range(1, k):
        eid, u = red[idx]
        idx += 1
        ru = dsu.find(u)
        ri = dsu.find(rts[i])
        r0 = dsu.find(rts[0])
        if ru == ri:
            out.append(f"{eid} {u} {r0}")
            dsu.unite(r0, ri)
        else:
            out.append(f"{eid} {u} {ri}")
            dsu.unite(ru, ri)
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()
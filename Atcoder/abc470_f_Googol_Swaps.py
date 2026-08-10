import sys

class MI:
    MOD = 998_244_353
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

class DSU:
    __slots__ = ('p', 'sz')
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1] * n
    def find(self, x):
        p = self.p
        while p[x] != x:
            p[x] = p[p[x]]
            x = p[x]
        return x
    def unite(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]

def solve():
    input = sys.stdin.buffer.readline
    N, M = map(int, input().split())
    S = input().strip().decode()

    dsu = DSU(N)
    for _ in range(M):
        A, B = map(int, input().split())
        dsu.unite(A - 1, B - 1)

    fac = [None] * (N + 1)
    fac[0] = MI(1)
    for i in range(1, N + 1):
        fac[i] = fac[i - 1] * i

    comp_sz = [0] * N
    cnt = [None] * N
    for i in range(N):
        r = dsu.find(i)
        comp_sz[r] += 1
        if cnt[r] is None:
            cnt[r] = [0] * 26
        cnt[r][ord(S[i]) - 97] += 1

    P = MI(1)
    Q = MI(1)
    has_repeat = False

    for r in range(N):
        if comp_sz[r] == 0:
            continue
        k = comp_sz[r]
        if k >= 2:
            P *= fac[k]
        for m in cnt[r]:
            if m >= 2:
                has_repeat = True
                Q *= fac[m]

    ans = P * Q.inv()
    if not has_repeat:
        ans *= MI(2).inv()
    print(ans)


if __name__ == '__main__':
    solve()
import sys

def solve():
    it = iter(map(int, sys.stdin.read().split()))
    ans = []
    for _ in range(next(it)):
        n = next(it)
        z = []
        for i in range(n):
            z.append((next(it), next(it)))
        def cal(z1, z2):
            a, b = z1
            c, d = z2
            return (a*c-b*d, a*d+c*b)
        f = 1
        for i in range(2, len(z)):
            if cal(z[0], z[i]) != cal(z[1], z[i - 1]):
                f = 0
                break
        if f : ans.append("Yes")
        else : ans.append("No")        
    sys.stdout.write('\n'.join(ans))
if __name__ == '__main__':
    solve()
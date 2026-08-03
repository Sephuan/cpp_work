import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    N, M = data[0], data[1]
    A = data[2 : 2 + N]
    bit = [0] * (M + 1)
    inv0 = 0
    for x in A:
        i = M
        tot = 0
        while i > 0:
            tot += bit[i]
            i -= i & -i
        i = x + 1
        le = 0
        while i > 0:
            le += bit[i]
            i -= i & -i
        inv0 += tot - le
        i = x + 1
        while i <= M:
            bit[i] += 1
            i += i & -i
    cnt = [0] * M
    for x in A: cnt[x] += 1
    seen = [0] * M
    delta = [0] * M
    for p in range(N):
        a = A[p]
        before_diff = p - seen[a]
        after_diff = (N - 1 - p) - (cnt[a] - 1 - seen[a])
        delta[M - 1 - a] += before_diff - after_diff
        seen[a] += 1
    ans = [0] * M
    cur = inv0
    for k in range(M):
        ans[k] = cur
        cur += delta[k]
    sys.stdout.write('\n'.join(map(str, ans)))

if __name__ == '__main__':
    main()
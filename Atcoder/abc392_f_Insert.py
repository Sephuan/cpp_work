import sys

def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    N = data[0]
    P = [0] + data[1 : 1 + N]
    bit = [0] * (N + 1)
    def add(idx, val):
        while idx <= N:
            bit[idx] += val
            idx += idx & -idx
    for i in range(1, N + 1):
        add(i, 1)
    def kth(k):
        idx = 0
        stp = 1 << (N.bit_length() - 1)
        while stp:
            nxt = idx + stp
            if nxt <= N and bit[nxt] < k:
                k -= bit[nxt]
                idx = nxt
            stp >>= 1
        return idx + 1

    ans = [0] * (N + 1)
    for i in range(N, 0, -1):
        pos = kth(P[i])
        ans[pos] = i
        add(pos, -1)
    sys.stdout.write(' '.join(map(str, ans[1 : ])))

if __name__ == "__main__":
    solve()
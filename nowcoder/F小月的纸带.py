import sys
from random import *
from collections import *

def solve():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])
    q = int(data[1])
    s = data[2]
    sz = 4 * n + 5
    lv = [0] * sz
    rv = [0] * sz
    cnt = [0] * (3 * sz)
    tag = [0] * sz
    def apply(u, k):
        lv[u] = (lv[u] + k) % 3
        rv[u] = (rv[u] + k) % 3
        i = 3 * u
        if k == 1:
            cnt[i], cnt[i + 1], cnt[i + 2] = cnt[i + 2], cnt[i], cnt[i + 1]
        elif k == 2:
            cnt[i], cnt[i + 1], cnt[i + 2] = cnt[i + 1], cnt[i + 2], cnt[i]
        tag[u] = (tag[u] + k) % 3
    def pu(u, a, b):
        lv[u] = lv[a]
        rv[u] = rv[b]
        i, j, m = 3 * u, 3 * a, 3 * b
        cnt[i] = cnt[j] + cnt[m]
        cnt[i + 1] = cnt[j + 1] + cnt[m + 1]
        cnt[i + 2] = cnt[j + 2] + cnt[m + 2]
        if rv[a] == lv[b]:
            cnt[i + rv[a]] -= 1
    def pd(u):
        k = tag[u]
        if k:
            apply(u * 2, k)
            apply(u * 2 + 1, k)
            tag[u] = 0
    def bd(u, l, r):
        if l == r:
            c = s[l - 1] - 65
            lv[u] = rv[u] = c
            cnt[3 * u + c] = 1
            return
        mid = l + r >> 1
        bd(u * 2, l, mid)
        bd(u * 2 + 1, mid + 1, r)
        pu(u, u * 2, u * 2 + 1)
    def upd(u, l, r, ql, qr):
        if ql <= l and r <= qr:
            apply(u, 1)
            return
        pd(u)
        mid = l + r >> 1
        if ql <= mid:
            upd(u * 2, l, mid, ql, qr)
        if qr > mid:
            upd(u * 2 + 1, mid + 1, r, ql, qr)
        pu(u, u * 2, u * 2 + 1)
    bd(1, 1, n)
    out = []
    p = 3
    for _ in range(q):
        if data[p] == b'1':
            l = int(data[p + 1])
            r = int(data[p + 2])
            p += 3
            upd(1, 1, n, l, r)
        else:
            p += 1
            out.append(str(cnt[3]))
    sys.stdout.write('\n'.join(out))


if __name__ == '__main__':
    solve()
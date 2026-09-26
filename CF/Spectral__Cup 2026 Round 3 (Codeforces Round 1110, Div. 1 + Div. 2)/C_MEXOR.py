import sys
from collections import *
from bisect import *
from math import *
input = sys.stdin.readline
II = lambda : int(input().strip())
I = lambda : input().strip()
def MI(e = int): return map(e, input().split())
def LMI(e = int): return list(map(e, input().split()))

'''
0, 1, 2, ... , n - 1


n = 9
0, 1, 2, ... , 8

8 = 1000
9 = 1001

10 = 1010
11 = 1011
12 = 1100
13 = 1101
14 = 1110
15 = 1111

0, 1, 2, 3, ..., n - 1
1, 2, 3, 4, ..., n     == X

T = X ^ k

if T < n:
    T, 0, 1, 2, 3, ..., n - 1
    0, 1, 2, 3, 4, ..., n - 1  == X ^ T

if T >= n:
    a = 1 << (T.bit_len - 1)
    b = T ^ a
    X ^ T == X ^ a ^ b

if n.bit_count() == 1:
    YES if k >= n else NO
'''
def sol():
    out = []
    n, k = MI()
    LIM = (1 << n.bit_length()) - 1
    if k > LIM:
        print("NO")
        return
    if n.bit_count() == 1 and k < n:
        print("NO")
        return
    print("YES")
    X = 0
    for i in range(1, n + 1):
        X ^= i
    T = X ^ k
    if T < n:
        out.append(str(T))
        for i in range(n):
            if i != T:
                out.append(str(i))
    else:
        a = 1 << (T.bit_length() - 1)
        b = T ^ a
        out.append(str(a))
        out.append(str(b))
        for i in range(n):
            if i != a and i != b:
                out.append(str(i))
    sys.stdout.write(' '.join(out) + '\n')

if __name__ == '__main__':
    T = 1
    T = II()
    for _ in range(T):
        sol()
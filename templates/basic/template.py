# $NAME
# $URL
import sys
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right

input = sys.stdin.readline


def solve() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    print(n, a)


def main() -> None:
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n; vector<ll> tree;
    explicit Fenwick(int n) : n(n), tree(n + 1){}

    void init() {
        tree.assign(n + 1, 0);
    }

    void add(int x, ll delta) {
        while (x <= n) {
            tree[x] += delta;
            x += x & -x;
        }
    }
    ll preSum(int x) {
        ll ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= x & -x;
        }
        return ans;
    }
    ll rangeSum(ll l, ll r) {
        if (l > r) return 0;
        return preSum(r) - preSum(l - 1);
    }
    // 前提：
    // 1. 每个位置保存的是非负频次
    // 2. 1 <= k <= 所有频次之和
    // 返回最小的 pos，使 preSum(pos) >= k
    int kth(ll k) {
        int pos = 0;
        ll acc = 0;
        int stp = 1;
        while ((stp << 1) <= n) stp <<= 1;
        for (; stp > 0; stp >>= 1) {
            int nxtPos = pos + stp;
            if (nxtPos <= n && acc + tree[nxtPos] < k) {
                pos = nxtPos;
                acc += tree[nxtPos];
            }
        }
        return pos + 1;
    }
};

struct Fenwick_ {
    int n;
    vector<long long> tree;
    Fenwick_(int n = 0) {
        init(n);
    }

    void init(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void add(int x, long long delta) {
        while (x <= n) {
            tree[x] += delta;
            x += x & -x;
        }
    }

    long long prefixSum(int x) const {
        long long answer = 0;

        while (x > 0) {
            answer += tree[x];
            x -= x & -x;
        }

        return answer;
    }
};

class RangeFenwick {
private:
    int n;
    Fenwick_ bit1;
    Fenwick_ bit2;

    void internalAdd(int x, long long delta) {
        if (x > n) {
            return;
        }

        bit1.add(x, delta);
        bit2.add(x, delta * (x - 1));
    }

public:
    RangeFenwick(int n)
        : n(n), bit1(n), bit2(n) {}

    void rangeAdd(int left, int right, long long delta) {
        internalAdd(left, delta);
        internalAdd(right + 1, -delta);
    }

    long long prefixSum(int x) const {
        long long sum1 = bit1.prefixSum(x);
        long long sum2 = bit2.prefixSum(x);

        return x * sum1 - sum2;
    }

    long long rangeSum(int left, int right) const {
        if (left > right) {
            return 0;
        }

        return prefixSum(right) - prefixSum(left - 1);
    }
};

int main() {
    int n = 5;
    vector<int> a{-1, 1, 4, 3, 5, 7};
    Fenwick fw(n);
    for (int i = 1; i <= n; ++ i) fw.add(i, a[i]);
    cout << fw.preSum(3) << endl;
    cout << fw.rangeSum(2, 3) << endl;
    cout << a[fw.kth(2)] << endl;
}
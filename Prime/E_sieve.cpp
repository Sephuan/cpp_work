#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
int primes[1'000'000], cnt;
bitset<N> st;

void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (long long j = 1LL * i * i; j <= n; j += i)
                st[j] = 1;
        }
    }
}

int main() {
    sieve(10'000'000);
    cout << primes[cnt - 1];
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+10;
int primes[6'000'010];
bool st[N];
int cnt = 0;

void ola(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) primes[++cnt] = i;
        for (int j = 1; primes[j] <= n / i; ++j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    ola(n);
    while (q--) {
        int k;
        cin >> k;
        cout << primes[k];
        if (q) cout << '\n';
    }
}
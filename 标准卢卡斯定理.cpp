#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXP = 100'005;
ll fact[MAXP], inv_fact[MAXP];

ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll modInv(ll a, ll p) {
    return qpow(a, p - 2, p);
}

void init(ll p) {
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i < p; ++i)
        fact[i] = fact[i - 1] * i % p;
    inv_fact[p - 1] = modInv(fact[p - 1], p);
    for (int i = p - 2; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % p;
}

ll C(ll n, ll m, ll p) {
    if (m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1;
    return fact[n] * inv_fact[m] % p * inv_fact[n - m] % p;
}

ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    int p = 100'003;
    init(p);

    while (T--) {
        ll n, m;
        cin >> n >> m;
        cout << lucas(n, m, p) << '\n';
    }
}
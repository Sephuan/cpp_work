#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;

ll qpow(ll a, ll b, ll mod) {
    ll res = 1; a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) res = (lll)res * a % mod;
        a = (lll)a * a % mod;
    }
    return res;
}

bool mr_test(ll n, ll a) {
    if (qpow(a, n - 1, n) != 1) return false;
    ll d = n - 1;
    while (d % 2 == 0) {
        d >>= 1;
        ll x = qpow(a, d, n);
        if (x == n - 1) return true;
        if (x != 1) return false;
    }
    return true;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    static const ll A[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
    };
    for (ll a : A) {
        if (n == a) return true;
        if (!mr_test(n, a)) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    cout << is_prime(n);
}
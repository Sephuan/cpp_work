#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define AC return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 10'000'005;

bitset<(size_t)1e7+5> st;
vector<int> primes((size_t)1e6+5);
int ith = 0;
void init() {
    st[0] = st[1] = 1;
    rep(i, 2, MAXN) {
        if (!st[i]) {
            primes[ith ++] = i;
            for (ll j = 1LL * i * i; j < MAXN; j += i) {
                st[j] = 1;
            }
        }
    }
}

vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 2; 1LL * i * i <= n; ++ i) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

ll countCoPrimes(int x, vector<int>& factors) {
    if (x <= 0) return 0;
    int k = factors.size();
    ll res = 0;
    for (int mask = 0; mask < (1 << k); ++ mask) {
        ll product = 1;
        int selectedCount = 0;
        for (int i = 0; i < k; ++ i) {
            if (mask & (1 << i)) {
                product *= factors[i];
                ++ selectedCount;
            }
        }
        ll countMultiples = x / product;
        if (selectedCount % 2 == 0) res += countMultiples;
        else res -= countMultiples;
    }
    return res;
}

void solve() {
    int l, r, n; cin >> l >> r >> n;
    if (!st[n]) {
        cout << (r - l + 1);
        return ;
    }
    ll ans = 0;
    auto it = lower_bound(primes.begin(), primes.begin() + ith, n); 
    -- it;
    int P = *it;
    vector<int> factors = findFactors(n);
    int R = min(r, P);
    if (l <= R) {
        ll len = R - l + 1;
        ll cr = countCoPrimes(R, factors);
        ll cl = countCoPrimes(l - 1, factors);
        ll coPrimeCnt = cr - cl;
        ans = (len << 1) - coPrimeCnt;
    }
    if (r > P) {
        map<int, int> dp;
        rrep(i, n - 1, P + 1) {
            int best = INF;
            rep1(j, i + 1, n) {
                int cand = gcd(i, j) + dp[j];
                best = min(best, cand);
            }
            dp[i] = best;
        }
        int L = max(l, P + 1);
        rep1(i, L, r) {
            ans += dp[i];
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

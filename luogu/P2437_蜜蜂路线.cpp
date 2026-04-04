#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

struct BigInt {
    vector<int> d;
    BigInt(int num = 0) {
        if (num == 0) d.push_back(0);
        while (num > 0) {
            d.push_back(num % 10);
            num /= 10;
        }
    }
    BigInt operator+(const BigInt& b) const {
        BigInt res;
        res.d.clear();
        int carry = 0;
        int i = 0;
        auto& rd = res.d, bd = b.d;
        while (i < bd.size() || i < d.size() || carry) {
            if (i < bd.size()) carry += bd[i];
            if (i < d.size()) carry += d[i];
            rd.push_back(carry % 10);
            carry /= 10;
            ++i;
        }
        return res;
    }
    void print() const {
        for (int i = d.size() - 1; i >= 0; --i)
            cout << d[i];
    }
};

void solve() {
    int m, n;
    cin >> m >> n;
    int c = n - m + 1;
    BigInt f1 = 1, f2 = 1, f = 0;
    rep1(i, 3, c) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    if (c == 1 || c == 2) cout << 1;
    else f.print();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

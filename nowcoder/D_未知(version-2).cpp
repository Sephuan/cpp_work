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
const int MAXN = 2'00'005;

void init() {

}

bool bpow(ll a, ll b, ll& r) {
    r = 1;
    while (b --) {
        r = r * a;
        if (r > 1000000000LL) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    vector<int> a;
    rep1(i, 1, n) {
        int t; cin >> t;
        mp[t] ++;
    }
    if (mp.count(1) && mp[1] > 1) {
        cout << "YES";
        return ;
    }
    if (mp.count(1)) {
        for (auto& [k, v] : mp) {
            if (k == 1) continue;
            if (v > 1) {
                cout << "YES";
                return ;
            }
        }
    }
    for (auto& [k, v] : mp) {
        if (k == 1) continue;
        a.push_back(k);
    }
    rep(i, 0, a.size()) {
        rep(j, 0, a.size()) {
            ll r;
            if (bpow(a[i], a[j], r) && mp.count(r)) {
                cout << "YES";
                return ;
            }
            if (r > 1000000000LL) break;
        }
    }
    cout << "NO";
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

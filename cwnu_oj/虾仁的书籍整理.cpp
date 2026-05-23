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
const int MAXN = 1'005;

void init() {

}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    rep1(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    auto cal = [&](int h) {
        ll cnt = 0;
        rep1(i, 1, n) cnt += abs(a[i] - h);
        return cnt;
    };
    int th = sum / n;
    ll d = LINF; int ah = 1e9;
    int l = 1, r = 2e5;
    while (l <= r) {
        int mid1 = l + (r - l + 1) / 3;
        int mid2 = r - (r - l + 1) / 3;
        ll c1 = cal(mid1), c2 = cal(mid2);
        if (c1 <= c2) {
            if (c1 <= d) {
                if ((c1 == d && mid1 < ah) || c1 != d) {
                    d = c1;
                    ah = mid1;
                }
            }
            r = mid2 - 1;
        } else {
            if (c2 <= d) {
                if ((c2 == d && mid2 < ah) || c2 != d) {
                    d = c2;
                    ah = mid2;
                }
            }
            l = mid1 + 1;
        }
    }
    /*
    rep1(i, th - 100, th + 100) {
        ll cd = cal(i);
        if (cd < d) {
            d = cd;
            ah = i;
        }
    }
    */

    /*
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 排序找中位数
    sort(a.begin(), a.end());

    // 根据公式，直接输出 (n-1)/2 位置的元素
    cout << a[(n - 1) / 2] << "\n";
    */

    cout << ah;
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

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
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

const double PI = acos(-1.0);
const int MAXN = 16'005;

void init() {

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector a(n + 1, 0);
    deque<int> dq_min, dq_max;
    vector<int> v_min, v_max;

    rep1(i, 1, n) cin >> a[i];

    rep1(i, 1, n) {
        if (!dq_min.empty() && dq_min.front() <= i - k) dq_min.pop_front();
        if (!dq_max.empty() && dq_max.front() <= i - k) dq_max.pop_front();

        while (!dq_min.empty() && a[dq_min.back()] >= a[i])
            dq_min.pop_back();
        while (!dq_max.empty() && a[dq_max.back()] <= a[i])
            dq_max.pop_back();

        dq_min.push_back(i);
        dq_max.push_back(i);

        if (i >= k) {
            v_min.push_back(a[dq_min.front()]);
            v_max.push_back(a[dq_max.front()]);    
        }
    }
    for (int i = 0; i < v_min.size(); i++) cout << v_min[i] << (i == v_min.size() - 1 ? "" : " ");
    cout << '\n';
    for (int i = 0; i < v_max.size(); i++) cout << v_max[i] << (i == v_max.size() - 1 ? "" : " ");
    cout << '\n';
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

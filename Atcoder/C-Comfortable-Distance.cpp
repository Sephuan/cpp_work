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

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve_1() {
    int N, L, R;
    cin >> N >> L >> R;
    string s;
    cin >> s;
    vector<int> a[26];
    rep(i, 0, N) a[s[i] - 'a'].push_back(i);
    ll ans = 0;
    rep(i, 0, N) {
        int l = i + L, r = min(i + R, N - 1);
        if (l >= N) break;
        int idx = s[i] - 'a';
        auto it1 = lower_bound(a[idx].begin(), a[idx].end(), l);
        auto it2 = upper_bound(a[idx].begin(), a[idx].end(), r);
        ans += it2 - it1;
    }
    cout << ans;
}

void solve_2() {
    int N, L, R;
    cin >> N >> L >> R;
    string s;
    cin >> s;
    vector<int> a(26, 0);
    ll ans = 0;
    int win_l = 0, win_r = 0;
    rep(i, 0, N) {
        int t_l = i + L, t_r = min(i + R, N - 1);
        if (t_l >= N) break;
        while (win_r <= t_r) {
            a[s[win_r] - 'a'] ++;
            win_r ++;
        }
        while (win_l < t_l) {
            a[s[win_l] - 'a'] --;
            win_l ++;
        }
        ans += a[s[i] - 'a'];
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve_2();
        if (T) {
            cout << '\n';
        }
    }
    AC
}

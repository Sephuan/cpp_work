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

void solve() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> h;
    int t;
    while (ss >> t) h.push_back(t);
    vector<int> r1, r2;
    rep(i, 0, h.size()) {
        auto it1 = upper_bound(r1.begin(), r1.end(), h[i], greater<>());
        if (it1 == r1.end()) r1.push_back(h[i]);
        else *it1 = h[i];
        auto it2 = lower_bound(r2.begin(), r2.end(), h[i]);
        if (it2 == r2.end()) r2.push_back(h[i]);
        else *it2 = h[i];
    }
    cout << r1.size() << endl << r2.size();
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

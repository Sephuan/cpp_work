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
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int N; cin >> N;
    string S; cin >> S;
    bool rev = false;
    deque<int> dq;
    rep1(i, 1, N) {
        if (S[i - 1] == 'o') {
            rev = !rev;
            if (rev) dq.push_back(i);
            else dq.push_front(i);
        } else {
            if (rev) dq.push_front(i);
            else dq.push_back(i);
        }
    }
    if (!rev) {
        rep(i, 0, N) {
            if (i) cout << ' ';
            cout << dq[i];
        }
    } else rrep(i, N - 1, 0) {
        if (i < N - 1) cout << ' ';
        cout << dq[i];
    }
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

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
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    if (N % 2 == 1 || (A + B) % 2 == 0) {
        cout << "No";
        return ;
    }
    string ans;
    ans.reserve(N * N);
    int r = A % 2 ? A : A - 1;
    rep1(i, 1, r - 1) {
        if (i & 1) {
            ans += string(N - 1, 'R');
        } else ans += string(N - 1, 'L');
        ans += 'D';
    }
    int cur = r;
    rep1(i, 1, N) {
        int nxt = cur == r ? r + 1 : r;
        if (i != B) {
            if (nxt > cur) ans += 'D';
            else ans += 'U';
            cur = nxt;
        }
        if (i < N) ans += 'R';
    }
    rep1(i, r + 2, N) {
        ans += 'D';
        if (i & 1) {
            ans += string(N - 1, 'L');
        } else ans += string(N - 1, 'R');
    }
    cout << "Yes" << endl;
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

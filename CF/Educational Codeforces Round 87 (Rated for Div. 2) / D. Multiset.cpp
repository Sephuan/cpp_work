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
const int MAXN = 1'000'005;


void init() {

}

struct Fenwick {
    int n; vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}
    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
    int kth(int k) {
        int pos = 0;
        int acc = 0;
        int stp = 1;
        while ((stp << 1) <= n) stp <<= 1;
        for (; stp > 0; stp >>= 1) {
            int nxtPos = pos + stp;
            if (nxtPos <= n && acc + bit[nxtPos] < k) {
                pos = nxtPos;
                acc += bit[nxtPos];
            }
        }
        return pos + 1;
    }
    void res() {
        int ans = 0;
        rep1(i, 1, n) {
            if (bit[i]) {
                ans = i;
                break;
            }
        }
        cout << ans;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> freq(n + 1);
    rep(i, 0, n) {
        int a; cin >> a;
        freq[a] ++;
    }
    Fenwick fw(n);
    rep1(i, 1, n) {
        if (freq[i]) {
            fw.add(i, freq[i]);
        }
    }
    while (q --) {
        int k; cin >> k;
        if (k < 0) {
            int val = fw.kth(-k);
            fw.add(val, -1);
        } else {
            fw.add(k, 1);
        }
    }
    fw.res();
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

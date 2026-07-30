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

int n;

vector<int> f(vector<int>& seq) {
    int pos = 0;
    vector<int> r(n);
    rep(i, 0, n) if (seq[i] == 1) { pos = i; break; }
    rep(i, 0, n) {
        r[i] = seq[(pos + i) % n];
    }
    return r;
}

vector<int> miniMax(vector<int>& seq, int mask, bool is_alice) {
    if (seq.size() == n) {
        return f(seq);
    }
    vector<int> best;
    bool first = true;
    rep1(x, 1, n) {
        if (mask & (1 << x)) continue;
        seq.push_back(x);
        vector<int> val = miniMax(seq, mask | (1 << x), !is_alice);
        seq.pop_back();
        if (first) {best = val; first = false;}
        else if (is_alice) { if (val < best) best = val; }
        else               { if (val > best) best = val; }
    }
    return best;
}

void solve1() {
    rep1(v, 1, 10) {
        n = v;
        vector<int> seq;
        vector<int> ans;
        ans = miniMax(seq, 0, true);
        rep(i, 0, n) cout << ans[i] << ' ';
        cout << endl;
    }
    /*
    1 
    1 2 
    1 3 2 
    1 3 2 4 
    1 4 2 3 5 
    1 4 3 5 2 6 
    1 5 2 4 6 3 7 
    1 5 4 6 3 7 2 8 
    1 6 2 5 7 4 8 3 9 
    1 6 5 7 4 8 3 9 2 10 
    */
}

void solve() {
    cin >> n;
    if (n & 1) {
        int m = n >> 1;
        cout << 1;
        if (!m) return ;
        int ev = 2, od = 3;
        rep1(i, 2, n) {
            cout << ' ';
            if (i == 3) cout << 2;
            else if (i & 1) cout << m + od ++;
            else cout << m + ev --;
        }
    } else {
        int m = n >> 1;
        cout << 1;
        int ev = 1, od = 0;
        rep1(i, 2, n) {
            cout << ' ';
            if (i & 1) cout << m + od --;
            else cout << m + ev ++;
        }
    }
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

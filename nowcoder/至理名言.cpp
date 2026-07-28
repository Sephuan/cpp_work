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
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3fLL;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 2'00'005;

void init() {

}

int ch[MAXN][36];
int passCnt[MAXN];
int tot = 0;
string S;

int id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return 26 + (c - '0');
}

void trieIns(string& s) {
    int u = 0;
    for (int i = 0; s[i]; ++ i) {
        int d = id(s[i]);
        if (!ch[u][d]) ch[u][d] = ++tot;
        u = ch[u][d];
        passCnt[u] ++;
    }
}

void trieEra(string& s) {
    int u = 0;
    rep(i, 0, s.size()) {
        u = ch[u][id(s[i])];
        passCnt[u] --;
    }
}

bool trieQue(string& s) {
    int u = 0;
    rep(i, 0, s.size()) {
        int d = id(s[i]);
        int v = ch[u][d];
        if (!v || passCnt[v] == 0)
            return false;
        u = ch[u][d];
    }
    return true;
}

void solve() {
    int n; cin >> n;
    unordered_map<string, int> cnt;
    cnt.reserve(1 << 19);
    while (n --) {
        int op;
        cin >> op >> S;
        if (op == 1) {
            int c = ++cnt[S];
            if (c == 1) trieIns(S);
            cout << c << endl;
        } else if (op == 2) {
            if (trieQue(S)) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
        } else {
            auto it = cnt.find(S);
            if (it != cnt.end() && it->se > 0) {
                it->se = 0;
                trieEra(S);
            }
        }
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

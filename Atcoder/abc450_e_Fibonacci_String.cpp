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

using countArray = array<ll, 26>;
const ll LIMIT = 1e18;

vector<countArray> buildPrefixCount(const string& s) {
    vector<countArray> prefix(s.size() + 1);
    prefix[0].fill(0);
    rep(i, 0, s.size()) {
        prefix[i + 1] = prefix[i];
        prefix[i + 1][s[i] - 'a'] ++;
    }
    return prefix;
}

ll getPrefixCount(
    ll k, ll targetCharacter, int m,
    const vector<ll>& length,
    const vector<countArray>& wholeCount,
    const vector<countArray>& prefixX,
    const vector<countArray>& prefixY
) {
    if (k == 0) return 0;
    int cur = m;
    ll ans = 0;
    while (cur >= 3) {
        if (k <= length[cur - 1]) cur -= 1;
        else {
            ans += wholeCount[cur - 1][targetCharacter];
            k -= length[cur - 1];
            cur -= 2;
        }
    }
    if (cur == 1) ans += prefixX[k][targetCharacter];
    else ans += prefixY[k][targetCharacter];
    return ans;
}

void solve() {
    string X, Y; cin >> X >> Y;
    int Q; cin >> Q;
    vector<countArray> prefixX = buildPrefixCount(X);
    vector<countArray> prefixY = buildPrefixCount(Y);
    vector<ll> length(3, 0);
    vector<countArray> wholeCount(3);
    length[1] = X.size(); length[2] = Y.size();
    wholeCount[1] = prefixX.back();
    wholeCount[2] = prefixY.back();
    while (length.back() < LIMIT) {
        size_t nxtIdx = length.size();
        ll nxtLen = length[nxtIdx - 1] + length[nxtIdx - 2];
        countArray nxtCount{};
        rep(c, 0, 26) {
            nxtCount[c] = 
                wholeCount[nxtIdx - 1][c] + wholeCount[nxtIdx - 2][c];
        }
        length.push_back(nxtLen);
        wholeCount.push_back(nxtCount);
    }
    int m = length.size() - 1;
    while (Q --) {
        ll L, R; cin >> L >> R;
        char C; cin >> C;
        int targetCharacter = C - 'a';
        ll rightPrefix = getPrefixCount(
            R, targetCharacter, m,
            length, wholeCount,
            prefixX, prefixY
        );
        ll leftPrefix = getPrefixCount(
            L - 1, targetCharacter, m,
            length, wholeCount,
            prefixX, prefixY
        );
        cout << rightPrefix - leftPrefix;
        if (Q) cout << endl;
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

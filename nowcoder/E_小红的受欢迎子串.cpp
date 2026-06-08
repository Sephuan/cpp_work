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
constexpr int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
constexpr int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 1'000'005;

void init() {

}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string w1 = "greet", w2 = "invite";
    vector<int> pref_greet(n + 2);
    vector suff_greet = pref_greet, 
        pref_invite = pref_greet,
        suff_invite = pref_greet;
    rep(i, 0, n) {
        int ptr1 = 0;
        int len1 = 0;
        rep(j, i, n) {
            while (ptr1 < 5 && w1[ptr1] != s[j]) ptr1 ++;
            if (ptr1 < 5) {
                len1 ++;
                ptr1 ++;
                pref_greet[j + 1] = max(pref_greet[j + 1], len1);
                suff_greet[i] = max(suff_greet[i], len1);
            } else break;
        }
        int ptr2 = 0;
        int len2 = 0;
        rep(j, i, n) {
            while (ptr2 < 6 && w2[ptr2] != s[j]) ptr2 ++;
            if (ptr2 < 6) {
                len2 ++;
                ptr2 ++;
                pref_invite[j + 1] = max(pref_invite[j + 1], len2);
                suff_invite[i] = max(suff_invite[i], len2);
            } else break;
        }
    }
    rep1(k, 1, n) {
        pref_greet[k] = max(pref_greet[k], pref_greet[k - 1]);
        pref_invite[k] = max(pref_invite[k], pref_invite[k - 1]);
    }
    rrep(k, n - 1, 0) {
        suff_greet[k] = max(suff_greet[k], suff_greet[k + 1]);
        suff_invite[k] = max(suff_invite[k], suff_invite[k + 1]);
    }
    int max_save = 0;
    rep1(k, 0, n) {
        int match_1 = pref_greet[k] + suff_invite[k];
        max_save = max(max_save, match_1);
        int match_2 = pref_invite[k] + suff_greet[k];
        max_save = max(max_save, match_2);
    }
    cout << 11 - max_save;
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

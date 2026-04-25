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

struct Node {
    int val;
    Node *pre, *nxt;
    Node(int v) : val(v), pre(nullptr), nxt(nullptr) {}
};

unordered_map<int, Node*> mp;
unordered_map<int, int> psz;

void mov(int a, int b) {
    Node* A = mp[a];
    Node* B = mp[b];
    Node* preA = A->pre;
    if (preA) preA->nxt = nullptr;
    B->nxt = A;
    A->pre = B;
}

void solve() {
    int N, Q; cin >> N >> Q;
    rep1(i, 1, N) mp[i] = new Node(i);
    while (Q --) {
        int a, b; cin >> a >> b;
        mov(a, b);
    }
    for (auto& [k, p] : mp) {
        if (p->pre == nullptr) {
            int cnt = 0;
            Node* cur = p;
            while (cur) {
                ++cnt;
                cur = cur->nxt;
            }
            psz[k] = cnt;
        }
    }
    rep1(i, 1, N) {
        if (i > 1) cout << ' ';
        if (psz.count(i)) cout << psz[i];
        else cout << 0; 
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

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

const double PI = acos(-1.0);
const int MAXN = 5'00'005;

void init() {

}

struct State {
    int dis;
    int id;
    bool operator<(const auto& other) const {
        if (dis != other.dis) return dis < other.dis;
        return id < other.id;
    };
};

State in1[MAXN], in2[MAXN], out[MAXN];
int lst[MAXN];
vector<int> adj[MAXN];

void dfs1(int u, int p) {
    in1[u] = {0, u};
    in2[u] = {-1, -1};
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            State cand = {in1[v].dis + 1, in1[v].id};
            if (in1[u] < cand) {
                in2[u] = in1[u];
                in1[u] = cand;
                lst[u] = v;
            } else if (in2[u] < cand) {
                in2[u] = cand;
            }
        }
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            State u_lst;
            if (v == lst[u]) {
                u_lst = max(out[u], in2[u]); 
            } else {
                u_lst = max(out[u], in1[u]);
            }
            out[v] = {u_lst.dis + 1, u_lst.id};
            dfs2(v, u);
        }
    }
}

void solve() {
    int N;
    cin >> N;
    rep(i, 1, N) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs1(1, 0);
    out[1] = {0, 1};
    dfs2(1, 0);
    rep1(i, 1, N) {
        State res = max(in1[i], out[i]);
        cout << res.id << '\n';
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

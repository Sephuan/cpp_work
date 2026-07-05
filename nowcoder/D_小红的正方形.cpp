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

struct Segment {
    int type;
    int fixed;
    int l, r;
};

vector<Segment> splitEdges(int x1, int y1, int x2, int y2) {
    int L = min(x1, x2);
    int R = max(x1, x2);
    int U = max(y1, y2);
    int D = min(y1, y2);
    vector<Segment> edges;
    edges.push_back({0, L, D, U});
    edges.push_back({0, R, D, U});
    edges.push_back({1, U, L, R});
    edges.push_back({1, D, L, R});
    return edges;
}

bool inRange(int x, int l, int r) {
    return l <= x && x <= r; 
}

void solve() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    vector<Segment> square1 = splitEdges(x1, y1, x2, y2);
    vector<Segment> square2 = splitEdges(x3, y3, x4, y4);
    set<pair<int, int>> pts;
    for (auto a : square1) {
        for (auto b : square2) {
            if (a.type == 0 && b.type == 0) {
                if (a.fixed != b.fixed) continue;
                int L = max(a.l, b.l);
                int R = min(a.r, b.r);
                if (L < R) {
                    cout << "inf";
                    return ;
                } else if (L == R) {
                    pts.insert({a.fixed, L});
                }
            } else if (a.type == 1 && b.type == 1) {
                if (a.fixed != b.fixed) continue;
                int L = max(a.l, b.l);
                int R = min(a.r, b.r);
                if (L < R) {
                    cout << "inf";
                    return ;
                } else if (L == R) {
                    pts.insert({L, a.fixed});
                }
            } else if (a.type == 0 && b.type == 1) {
                int x = a.fixed;
                int y = b.fixed;
                if (inRange(x, b.l, b.r) && inRange(y, a.l, a.r)) {
                    pts.insert({x, y});
                }
            } else {
                int x = b.fixed;
                int y = a.fixed;
                if (inRange(x, a.l, a.r) && inRange(y, b.l, b.r)) {
                    pts.insert({x, y});
                }
            }
        }
    }
    cout << pts.size();
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

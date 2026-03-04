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

const int MAXN = 2'00'005;

void init() {

}

int rev(int a) {
    int r = 0;
    while (a) {
        r = r * 10 + a % 10;
    }
    return r;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if (a == b) {cout << 0; return ;}
    queue<int> q;
    vector dis(1'000'005, -1);
    q.push(a);
    dis[a] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        int nxt = t + k;
        if (nxt <= 1'000'000 && dis[nxt] == -1) {
            dis[nxt] = dis[t] + 1;
            if (nxt == b) {
                cout << dis[nxt];
                return ;
            }
            q.push(nxt);
        }
        if (t % 10) {
            int nxt = rev(t);
            if (nxt <= 1'000'000 && dis[nxt] == -1) {
                dis[nxt] = dis[t] + 1;
                if (nxt == b) {
                    cout << dis[nxt];
                    return ;
                }
            }
            q.push(nxt);
        }
    }
    cout << "-1";
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

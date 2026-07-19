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

ll Mod(ll x, ll M) {
    x %= M;
    if (x < 0) x += M;
    return x;
}

void solve() {
    int N; ll M; cin >> N >> M;
    vector<ll> A(N), B(N - 1);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N - 1) cin >> B[i];
    vector<pair<ll, ll>> events;
    int c = N & 1;
    ll val = 0;
    ll F0 = 0;
    bool up = true;
    rep(i, 0, N) {
        F0 += val;
        if (up) {
            ll pos = M - 1 - val;
            if (pos < M - 1) events.push_back({pos, -M});
        } else {
            ll pos = val;
            if (pos < M - 1) events.push_back({pos, +M});
        }
        if (i + 1 < N) {
            val = Mod(B[i] - A[i] - A[i + 1] - val, M);
            up = !up;
        }
    }
    sort(events.begin(), events.end());
    ll curT = 0, curF = F0;
    ll ans = curF;
    for (int i = 0; i < events.size(); ) {
        ll pos = events[i].fi;
        ll extra = 0;
        while (i < events.size() && events[i].fi == pos) {
            extra += events[i].se;
            i ++;
        }
        curF += c * (pos + 1 - curT) + extra;
        curT = pos + 1;
        ans = min(ans, curF);
    }
    cout << ans;
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

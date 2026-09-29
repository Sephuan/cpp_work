#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int BITS = 30;
const int MAXP = 200'005 * 31;

int ch[MAXP][2];
int cnt[MAXP];
int tot = 0;

void add(int x, int delta = 1) {
    int u = 0;
    cnt[u] += delta;
    for (int b = BITS - 1; b >= 0; -- b) {
        int v = (x >> b) & 1;
        if (!ch[u][v]) ch[u][v] = ++tot;
        u = ch[u][v];
        cnt[u] += delta;
    }
}

int queryMax(int x) {
    int u = 0, ans = 0;
    for (int b = BITS - 1; b >= 0; -- b) {
        int v = (x >> b) & 1;
        if (ch[u][v ^ 1] && cnt[ch[u][v ^ 1]] > 0) {
            ans |= (1 << b);
            u = ch[u][v ^ 1];
        } else u = ch[u][v];
    }
    return ans;
}

int queryMin(int x) {
    int u = 0, ans = 0;
    for (int b = BITS - 1; b >= 0; -- b) {
        int v = (x >> b) & 1;
        if (ch[u][v] && cnt[ch[u][v]] > 0)
            u = ch[u][v];
        else {
            ans |= (1 << b);
            u = ch[u][v ^ 1];
        }
    }
    return ans;
}

ll cntLess(int x, int lim) {
    int u = 0; ll res = 0;
    for (int b = BITS - 1; b >= 0; -- b) {
        int xb = (x >> b) & 1, lb = (lim >> b) & 1;
        if (lb) {
            if (ch[u][xb]) res += cnt[ch[u][xb]];
            u = ch[u][xb ^ 1];
        } else {
            u = ch[u][xb];
        }
        if (!u || cnt[u] == 0) break;
    }
    return res;
}

ll cntGeq(int x, int lim) {
    int u = 0; ll res = 0;
    for (int b = BITS - 1; b >= 0; -- b) {
        int xb = (x >> b) & 1, lb = (lim >> b) & 1;
        if (lb) {
            u = ch[u][xb ^ 1];
        } else {
            if (ch[u][xb ^ 1]) res += cnt[ch[u][xb ^ 1]];
            u = ch[u][xb];
        }
        if (!u || cnt[u] == 0) break;
    }
    if (u) res += cnt[u];
    return res;
}




#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300'005;

int ch[MAXN][26];
int cnt[MAXN];
int ed[MAXN];
int tot = 0;

void ins(string& s, int delta = 1) {
    int u = 0;
    cnt[u] += delta;
    for (char c : s) {
        int v = c - 'a';
        if (!ch[u][v]) ch[u][v] = ++tot;
        u = ch[u][v];
        cnt[u] += delta;
    }
    ed[u] += delta;
}

int cntWord(string& s) {
    int u = 0;
    for (char c : s) {
        int v = c - 'a';
        if (!ch[u][v]) return 0;
        u = ch[u][v];
    }
    return ed[u];
}

int cntPref(string& s) {
    int u = 0;
    for (char c : s) {
        int v = c - 'a';
        if (!ch[u][v]) return 0;
        u = ch[u][v];
    }
    return cnt[u];
}
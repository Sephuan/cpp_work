#include <bits/stdc++.h>
using namespace std;

vector<int> buildPi(string& s) {
    int m = s.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++ i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j ++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmpFindAll(string& txt, string& pat) {
    vector<int> pos;
    if (pat.empty()) return pos;
    vector<int> pi = buildPi(pat);
    int n = txt.size();
    int m = pat.size();
    int j = 0;
    for (int i = 0; i < n; ++ i) {
        while (j > 0 && txt[i] != pat[j]) {
            j = pi[j - 1];
        }
        if (txt[i] == pat[j]) j ++;
        if (j == m) {
            pos.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return pos;
}

int main() {
    string t = "abababc", s = "abab";
    vector pos = kmpFindAll(t, s);
    for (int i : pos) cout << i << endl;
}
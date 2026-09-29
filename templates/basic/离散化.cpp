#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<int> a{1000, -7, 1, 1000};
    vector<int> val = a;
    ranges::sort(val);
    val.erase(unique(val.begin(), val.end()), val.end());
    vector<int> rank(n);
    for (int i = 0; i < n; ++ i) {
        rank[i] = lower_bound(val.begin(), val.end(), a[i])
            - val.begin() + 1;
    }
    for (int v : rank) cout << v << ' ';
}
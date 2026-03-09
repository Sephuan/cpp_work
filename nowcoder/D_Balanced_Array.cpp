#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll ans = 0;
        int l = 0;
        deque<int> minA, maxA;
        for (int r = 0; r < n; ++r) {
            while (!minA.empty() && a[minA.back()] >= a[r])
                minA.pop_back();
            minA.push_back(r);
            while (!maxA.empty() && a[maxA.back()] <= a[r])
                maxA.pop_back();
            maxA.push_back(r);
            while (a[maxA.front()] - a[minA.front()] > 1) {
                if (maxA.front() == l) maxA.pop_front();
                if (minA.front() == l) minA.pop_front();
                l ++;
            }
            ans += r - l + 1;
        }
        cout << ans;
        if (T) cout << '\n';
    }
}
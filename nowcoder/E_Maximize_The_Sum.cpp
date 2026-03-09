#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cnt1 = 0;
        for(int i = 0; i < n; ++i) {
            char t;
            cin >> t;
            if(t ^ 48) cnt1++;
        }
        cout << (cnt1 ? (cnt1 == n ? n : n-1) : 0);
        if (T) cout << '\n';
    }
}
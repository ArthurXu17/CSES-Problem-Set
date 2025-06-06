

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int INF = 1e9 + 5;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (auto & x : a) {
        cin >> x;
    }
    vector<int> dp(n+1, INF); // dp[i] = smallest last element of subsequence of length i
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        assert(it != dp.begin());
        int length = it - dp.begin();
        dbg(length);
        dp[length] = min(a[i], dp[length]);
        dbg(dp);
    }
    dbg(dp);
    for (int i = n; i >= 0; i--) {
        if (dp[i] != INF) {
            cout<<i<<endl;
            return 0;
        }
    }
}
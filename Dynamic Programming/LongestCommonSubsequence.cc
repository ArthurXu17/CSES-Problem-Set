

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for (auto & x : a) {
        cin >> x;
    }
    for (auto & x : b) {
        cin >> x;
    }
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // dp[i][j] = LCS for a[0...i] to b[0...j]
    if (a[0] == b[0]) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }

    set<int> seen = {a[0]};
    for (int i = 1; i < n; i++) {
        seen.insert(a[i]);
        if (seen.count(b[0])) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }

    seen = {b[0]};
    for (int j = 1; j < m; j++) {
        seen.insert(b[j]);
        if (seen.count(a[0])) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    dbg(dp);
    cout<<dp.back().back()<<'\n';
    vector<int> r;
    int i = n-1;
    int j = m - 1;
    while (i >= 0 && j >= 0) {
        if (dp[i][j] == 0) {
            break;
        }
        dbg(i);
        dbg(j);
        if (a[i] == b[j]) {
            r.push_back(a[i]);
            i--;
            j--;
        } else if (i > 0 && dp[i][j] == dp[i-1][j]) {
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j-1]) {
            j--;
        } else {
            assert(false);
        }
    }
    reverse(r.begin(), r.end());
    for (auto & x :r) {
        cout<<x<<" ";
    }
    cout<<'\n';
}
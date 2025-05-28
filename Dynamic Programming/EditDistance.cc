

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int INF = 1e9;


int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (m < n) {
        swap(s, t);
        swap(n, m);
    }
    assert(n <= m);
    assert((int) s.size() == n);
    assert((int) t.size() == m);
    vector<vector<int>> dp(n, vector<int>(m, INF));
    // dp[i][j] = edit distance for s[0...i] to t[0...j]
    if (s[0] == t[0]) {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }

    set<char> seen = {s[0]};
    for (int i = 1; i < n; i++) {
        seen.insert(s[i]);
        if (seen.count(t[0])) {
            dp[i][0] = i;
        } else {
            dp[i][0] = i+1;
        }
    }

    seen = {t[0]};
    for (int j = 1; j < m; j++) {
        seen.insert(t[j]);
        if (seen.count(s[0])) {
            dp[0][j] = j;
        } else {
            dp[0][j] = j+1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            } else {
                dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            }
        }
    }
    dbg(dp);
    cout<<dp.back().back()<<'\n';
}


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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
    for (int i = 1; i <= min(a, b); i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            // horizontal split
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            // vertical split
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    dbg(dp);
    cout<<dp.back().back()<<'\n';
}
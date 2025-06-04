

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll NEGINF = -1e18;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (auto & x : a) {
        cin >> x;
    }
    vector<ll> psa = a;
    for (int i = 1; i < n; i++) {
        psa[i] += psa[i-1];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0)); 
    // dp[i][j] is maximum score for subarray (i,j) if player 1 moves first, i.e if (i+j) % 2 == p1
    // otherwise dp[i][j] stores the maximum score for player 2, which moves first if (i+j) % 2 != p1
    // dp[i][j] = max(a[i] + (sum[i+1, j] - dp[i+1][j]), a[j] + (sum[i, j-1] - dp[i][j-1]))

    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int diff = 1; diff <= n-1; diff++) {
        for (int i = 0; i < n - diff; i++) {
            int j = i + diff;
            ll op1 = a[i] + psa[j] - psa[i] - dp[i+1][j];
            ll op2 = a[j] + psa[j-1] - dp[i][j-1];
            if (i > 0) {
                op2 -= psa[i-1];
            }
            dp[i][j] = max(op1, op2);
        }
    }
    dbg(dp);
    cout<<dp[0][n-1]<<'\n';
}
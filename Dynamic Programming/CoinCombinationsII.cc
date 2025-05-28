#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>
 
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x;
    cin >>n>>x;
    int mod = 1000000007;
    vector<int> dp(x + 1, 0);
    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    // on the jth iteration, dp[i][j] = number of ways to make value i, using only first j denominations and the last coin used is denomination j
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            int c = coins[j];
            if (i - c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod;
                if (i == c) {
                    dp[i]++;
                    dp[i] %= mod;
                }
            }
        }
        dbg(dp);
    }
    cout<<dp.back()<<endl;
}
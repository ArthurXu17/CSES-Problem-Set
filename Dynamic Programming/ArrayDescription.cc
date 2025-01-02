#include <bits/stdc++.h>

using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> nums;
    int mod = 1000000007;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    // dp[i][j] = num arrays up to index i with last digit j
    if (nums[0] == 0) {
        dp[0] = vector<int>(m + 1, 1);
    } else {
        dp[0][nums[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] == 0) {
            for (int j = 2; j < m; j++) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= mod;
            }
            dp[i][m] += dp[i-1][m];
            dp[i][m] %= mod;
            dp[i][m] += dp[i-1][m-1];
            dp[i][m] %= mod;

            
            dp[i][1] += dp[i-1][1];
            dp[i][1] %= mod;
            dp[i][1] += dp[i-1][2];
            dp[i][1] %= mod;
        } else {
            dp[i][nums[i]] += dp[i-1][nums[i]];
            dp[i][nums[i]] %= mod;
            if (nums[i] + 1 <= m)  {
                dp[i][nums[i]] += dp[i-1][nums[i] + 1];
                dp[i][nums[i]] %= mod;
            }
            
            if (nums[i] - 1 >= 1)  {
                dp[i][nums[i]] += dp[i-1][nums[i] - 1];
                dp[i][nums[i]] %= mod;
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= m; i++) {
        result += dp[n-1][i];
        result %= mod;
    }
    cout<<result<<endl;
}
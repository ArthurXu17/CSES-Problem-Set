#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> grid;
    string str; 
    int mod = 1000000007;
    for (int i = 0; i < n; i++) {
        cin >> str;
        grid.push_back(str);
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[0][0] != '*') {
        dp[0][0] = 1;
    } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                continue;
            }
            if (i - 1 >= 0 && grid[i-1][j] != '*') {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            if (j - 1 >= 0 && grid[i][j-1] != '*') {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;

}

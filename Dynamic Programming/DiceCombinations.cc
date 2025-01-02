#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >>n;
    int mod = 1000000007;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= min(6, n); i++) {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp.back()<<endl;
}
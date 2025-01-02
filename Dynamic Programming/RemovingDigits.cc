#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >>n;
    int mod = 1000000007;
    vector<int> dp(n + 1, INT_MAX);
    for (int i = 1; i <= min(9, n); i++) {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++) {
        string str = to_string(i);
        for (auto & ch : str) {
            int d = ch - '0';
            dp[i] = min(dp[i], 1 + dp[i-d]);
        }
    }
    cout<<dp.back()<<endl;
}
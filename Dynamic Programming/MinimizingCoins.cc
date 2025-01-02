#include <bits/stdc++.h>

using namespace std;
int main() {
    int n,x;
    cin >>n>>x;
    int mod = 1000000007;
    vector<int> dp(x + 1, INT_MAX);
    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }
    for (auto & c : coins) {
        if (c <= x) {
            dp[c] = 1;
        }
    }
    for (int i = 1; i <= x; i++) {
        for (auto & c : coins) {
            if (i - c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i-c]);
            }
        }
    }
    int result = dp.back();
    if (result == INT_MAX) {
        cout<<-1<<endl;
    } else {
        cout << result<<endl;
    }
}
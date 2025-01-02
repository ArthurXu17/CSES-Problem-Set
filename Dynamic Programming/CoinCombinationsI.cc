#include <bits/stdc++.h>

using namespace std;
int main() {
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
    for (auto & c : coins) {
        if (c <= x) {
            dp[c] = 1;
        }
    }
    for (int i = 1; i <= x; i++) {
        for (auto & c : coins) {
            if (i - c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp.back()<<endl;
}


#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;


int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> w(n, 0);
    for (auto & t : w) {
        cin >> t;
    }
    sort(w.begin(), w.end());
    vector<pii> dp((1<<n), {INT_MAX, INT_MAX});
    // dp[S] = {k, W}, where k is the minimum number of elevators for subset S and W is the min weight amongst all elevators in the minimum number of elevators 
    dp[0] = {1, 0};
    for (int S = 1; S < (1 << n); S++) {
        for (int i = 0; i < n; i++) {
            bitset<32> b(S);
            if (b[i]) {
                auto [kPrev, wPrev] = dp[S ^ (1 << i)]; // S xor 2^i is the set without i
                if (wPrev + w[i] <= x) {
                    dp[S] = min(dp[S], {kPrev, wPrev + w[i]});
                } else {
                    dp[S] = min(dp[S], {kPrev + 1, min(w[i], wPrev)});
                }
            }
        }
    }
    cout<<dp.back().first<<'\n';
}
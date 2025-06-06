

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
    int n;
    cin >> n;
    vector<array<ll, 3>> a;
    vector<int> ends;
    for (int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        a.push_back({y, x, p});
        ends.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(ends.begin(), ends.end());
    // sort by end times
    vector<ll> dp(n, 0);
    vector<ll> dpmax(n, 0);
    dp[0] = a[0][2];
    dpmax[0] = dp[0]; 
    for (int i = 1; i < n; i++) {
        auto [e, s, p] = a[i];
        auto it = lower_bound(ends.begin(), ends.end(), s);
        if (it == ends.begin()) {
            dp[i] = p;
        } else {
            it--;
            int j = it - ends.begin();
            dp[i] = p + dpmax[j];
        }
        dpmax[i] = max(dp[i], dpmax[i-1]);
    }
    
    dbg(dp);
    dbg(dpmax);
    cout<<dpmax.back()<<endl;
    
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h,s;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        h.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.push_back(t);
    }
    vector<ll> dp(x + 1, 0); 
    //dp[i] max pages obtainable using with cost at most i
    for (int i = 0; i < n; i++) {
        for (int w = x; w >= 0; w--) {
            if (w - h[i] >= 0) {
                //auto newValue = max(dp[i], dp[w-h[i]] + s[i]);
                //cout<<i<<", "<<w<<": "<<newValue<<endl;
                dp[w] = max(dp[w], dp[w-h[i]] + s[i]);
            }
        }
    }
    //for (int i = 0; i <= x; i++) {
    //    cout<<dp[i]<<" ";
    //}
    //cout<<endl;
    cout<<dp.back()<<"\n";


}
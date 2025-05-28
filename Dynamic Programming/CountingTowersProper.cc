#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>
 
using namespace std;

using uint = unsigned int;
const uint MOD = 1e9+7;
template<uint mod = MOD> struct mint {
    uint x;
 
    mint() : x(0) {}
    mint(long long _x) {
        _x %= mod;
        if (_x < 0) _x += mod;
        x = _x;
    }
 
    mint& operator += (const mint &a) {
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator -= (const mint &a) {
        x += mod - a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator *= (const mint &a) {
        x = (unsigned long long)x * a.x % mod;
        return *this;
    }
    mint pow(long long pw) const {
        mint res = 1;
        mint cur = *this;
        while(pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
    mint inv() const {
        assert(x != 0);
        uint t = x;
        uint res = 1;
        while(t != 1) {
            uint z = mod / t;
            res = (unsigned long long)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }
    mint& operator /= (const mint &a) {
        return *this *= a.inv();
    }
    mint operator + (const mint &a) const {
        return mint(*this) += a;
    }
    mint operator - (const mint &a) const {
        return mint(*this) -= a;
    }
    mint operator * (const mint &a) const {
        return mint(*this) *= a;
    }
    mint operator / (const mint &a) const {
        return mint(*this) /= a;
    }
 
    bool operator == (const mint &a) const {
        return x == a.x;
    }
    bool operator != (const mint &a) const {
        return x != a.x;
    }
    bool operator < (const mint &a) const {
        return x < a.x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int N = 0;
    vector<int> tests(t, 0);
    for (auto & x : tests) {
        cin >> x;
        N = max(N, x);
    }
    vector<vector<mint<MOD>>> dp(N + 1, vector<mint<MOD>>(2, 0));
    // dp[i][0] = number of ways where the last block is connected
    // dp[i][1] = number of ways where the last block is not connected
    dp[1] = {1, 1};
    for (int n = 2; n <= N; n++) {
        dp[n][0] = mint(4)*dp[n-1][0] + dp[n-1][1];
        dp[n][1] = dp[n-1][0] + mint(2) * dp[n-1][1];
    }
    
    for (auto & n : tests) {
        cout<<(dp[n][0] + dp[n][1]).x<<'\n';
    }
}
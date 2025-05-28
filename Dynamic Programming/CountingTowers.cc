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
    vector<mint<MOD>> dp(N + 1, 0);
    vector<mint<MOD>> dpsum(N + 1, 0);
    vector<mint<MOD>> triangle(N + 1, 0);
    
    dp[0] = 1;
    dpsum[0] = 1;
    mint pow4(1);
    for (int n = 1; n <= N; n++) {
        dp[n] += pow4;
        pow4 *= 4;
        dp[n] += dpsum[n-1];
        if (n >= 2) {
            triangle[n] = mint(4) * triangle[n-1] + dpsum[n-2];
        }
        dp[n] += triangle[n];
        dpsum[n] = dpsum[n-1] + dp[n];
    }

    for (auto & n : tests) {
        cout<<dp[n].x<<'\n';
    }
    /*n^3
    for (int n = 1; n <= 6; n++) {
        dp[n] += (1 << (2*(n-1)));
        for (int j = 0; j <= n-1; j++) {
            dp[n] += dp[j]; 
        }
        for (int j = 1; j <= n-1; j++) {
            for (int k = j; k <= n-1; k++) {
                dp[n] += dp[j-1] * (1 << (2*(n-k -1)));
            }
        }
        cout<<n<<": "<<dp[n]<<'\n'; 
    }
    */
    /* n^2
    mint pow2(1);
    for (int n = 1; n <= 1337; n++) {
        dp[n] += pow2;
        pow2 *= 4;
        dp[n] += dpsum[n-1];
        mint pow4 = 1;
        mint pow4sum = 1;
        for (int k = 1; k <= n-2; k++) {
            pow4 *= 4;
            pow4sum += pow4;
        }
        for (int j = 0; j <= n-2; j++) {
            dp[n] += dp[j] * pow4sum;
            pow4sum -= pow4;
            pow4 /= 4;
        }
        dpsum[n] = dpsum[n-1] + dp[n]; 
    }
    */
    /*for (int i = 1; i <= 6; i++) {
        cout<<i<<": "<<dp[i].x<<'\n';
    }
    cout<<dp.back().x<<'\n';*/
}
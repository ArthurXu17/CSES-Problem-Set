

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

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
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if (sum % 2 == 1) {
        cout<<"0\n";
        return 0;
    }
    // return number of ways to sum to sum, using 1,...,n divided by 2

    vector<vector<mint<MOD>>> dp(sum/2 + 1, vector<mint<MOD>>(n+1, 0));
    // dp[i][j] = number of ways to sum to i using 1,...,j
    dp[0] = vector<mint<MOD>>(n+1, 1);
    for (int i = 1; i <= sum/2; i++) {
        for (int j = 1; j <= n; j++) {
            // either use j or don't use j
            dp[i][j] += dp[i][j-1];
            if (i - j >= 0) {
                dp[i][j] += dp[i-j][j-1];
            }
        }
    }
    //dbg(dp);
    cout<<(dp[sum/2][n]/ 2).x<<'\n';
}
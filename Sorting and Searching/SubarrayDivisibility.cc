#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll t;
    vector<ll> nums;
    for (int i = 0; i < n; i++) {
        cin >> t;
        t %= n;
        if (t < 0) {
            t += n;
        }
        nums.push_back(t);
    }
    vector<ll> psa = nums;
    ll result = 0;
    if (nums[0] == 0) {
        result++;
    }
    for (int i = 1; i < n; i++) {
        psa[i] += psa[i-1];
        psa[i] %= n;
        if (psa[i] == 0) {
            result++;
        }
    }
    // summing over i, j such that psa[j] - psa[i] = 0 (mod n)
    map<ll, ll> occurences;
    for (int j = 0; j < n; j++) {
        if (occurences.count(psa[j])) {
            result += occurences[psa[j]];
            occurences[psa[j]]++;
        } else {
            occurences[psa[j]] = 1;
        }
    }
    cout<<result<<endl;

}
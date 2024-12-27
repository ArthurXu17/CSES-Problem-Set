#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll t;
    vector<ll> nums;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    vector<ll> psa = nums;
    ll result = 0;
    if (nums[0] == k) {
        result++;
    }
    for (int i = 1; i < n; i++) {
        psa[i] += psa[i-1];
        if (psa[i] == k) {
            result++;
        }
    }
    // summing over i, j such that psa[j] - psa[i] = k
    // at index j, we need an occurence of psa[j] - k
    map<ll, ll> occurences;
    for (int j = 0; j < n; j++) {
        ll target = psa[j] - k;
        if (occurences.count(target)) {
            result += occurences[target];
        }
        if (occurences.count(psa[j])) {
            occurences[psa[j]]++;
        } else {
            occurences[psa[j]] = 1;
        }
    }
    cout<<result<<endl;

}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, a, d;
    ll result = 0;
    cin >> n;
    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        result += d;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end(), greater());
    for (int i = 1; i <= arr.size(); i++) {
        ll temp = (ll) i * arr[i-1];
        result -= temp;
    }
    cout<<result<<endl;
}
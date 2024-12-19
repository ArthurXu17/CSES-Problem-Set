#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr;
    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }   
    vector<ll> psa(n+1, 0);

    for (int i = 1; i <= n; i++) {
        psa[i] = arr[i-1] + psa[i-1];
    }
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout<<psa[b] - psa[a-1]<<endl;;
    }
}
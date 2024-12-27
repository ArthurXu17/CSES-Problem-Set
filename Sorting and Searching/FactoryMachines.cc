#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> k;
    int ki;
    for (int i = 0; i < n; i++) {
        cin >> ki;
        k.push_back(ki);
    }
    ll m = k[0];
    for (auto & ki : k) {
        m = max((ll) ki, m);
    }
    ll left = 1;
    ll right = m * t;
    while (left < right) {
        ll mid = (left + right) / 2;
        //cout<<"Mid: "<<mid<<endl;
        ll numMachines = 0;
        for (auto & ki : k) {
            numMachines += mid / ki;
            //cout<<"ki: "<<ki<<endl;
            //cout<<"numMachines: "<<numMachines<<endl;
        }
        if (numMachines < t) { // answer is in the range [mid + 1, right]
            left = mid + 1;
        } else { // answer in the range [left, right]
            right = mid;
        }
    }
    cout<<left<<endl;

}
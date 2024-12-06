#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> times;
    int time;
    for (int i = 0; i < n; i++) {
        cin >> time;
        times.push_back({time, 1});
        cin >> time;
        times.push_back({time, -1});
    }
    sort(times.begin(), times.end());
    int maxCustomer = 1;
    int curCustomer = 0;
    for (auto & p : times) {
        curCustomer += p[1];
        maxCustomer = max(maxCustomer, curCustomer);
    }
    cout<<maxCustomer<<endl;
}
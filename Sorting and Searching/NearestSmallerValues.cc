#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int t;
    vector<int> nums; // [finish, start]
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.emplace_back(t);
    }
    vector<int> result;
    vector<pair<int, int>> increasingHeights;
    increasingHeights.emplace_back(nums[0], 0);
    result.push_back(-1);
    for (int i = 1; i < n; i++){
        while (!increasingHeights.empty() && nums[i] <= increasingHeights.back().first) {
            increasingHeights.pop_back();
        }
        if (increasingHeights.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(increasingHeights.back().second);
        }
        increasingHeights.emplace_back(nums[i], i);
    }
    for (auto & r : result) {
        cout<<r + 1<<" ";
    }
    cout<<endl;
}
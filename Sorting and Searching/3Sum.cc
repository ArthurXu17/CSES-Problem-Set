#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, m, t;
    vector<pii> nums;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        nums.emplace_back(m, i);
    }
    sort(nums.begin(), nums.end());
    int a = -1;
    int b = -1;
    int c = -1;
    for (int i = 0; i < n; i++) {
        int curTarget = t - nums[i].first;
        if (curTarget <= nums[i+1].first) {
            continue;
        }
        int left = i+1;
        int right = n - 1;
        while (nums[left].first + nums[right].first != curTarget && left < right && left < n && right > i) {
            if (nums[left].first + nums[right].first > curTarget) {
                right--;
            } else {
                left++;
            }
        }
        if (nums[left].first + nums[right].first == curTarget && left != right) {
            cout<<nums[i].second<<" "<<nums[left].second<<" "<<nums[right].second<<" "<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}
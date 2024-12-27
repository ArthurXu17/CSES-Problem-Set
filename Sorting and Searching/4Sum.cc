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
    /*for (auto & [a,b] : nums) {
        cout<<a<<", "<<b<<endl;
    }*/
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int curTarget = t - nums[i].first - nums[j].first;
            if (curTarget <= nums[j+1].first) {
                continue;
            }
            int left = j+1;
            int right = n - 1;
            while (nums[left].first + nums[right].first != curTarget && left < right && left < n && right > j) {
                if (nums[left].first + nums[right].first > curTarget) {
                    right--;
                } else {
                    left++;
                }
            }
            if (nums[left].first + nums[right].first == curTarget && left < right) {
                /*cout<<"i: "<<i<<endl;
                cout<<"j: "<<j<<endl;
                cout<<"left: "<<left<<endl;
                cout<<"right: "<<right<<endl;*/
                cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[left].second<<" "<<nums[right].second<<" "<<endl;
                return 0;
            }
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}
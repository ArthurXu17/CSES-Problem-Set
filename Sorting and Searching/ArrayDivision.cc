#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    int x;
    for (int i = 0 ; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    ll right = 0;
    ll left = nums[0];
    for (auto & num : nums) {
        right += num;
        left = max((ll)num, left);
    }
    // the result is always greater than or equal to the max element of nums
    while (left < right) {
        
        ll mid = (left + right) / 2;
        int subArrays = 0;
        ll curSum = 0;
        //cout<<"Cur Sum Values: "<<endl;
        for (auto & m : nums) {
            if (curSum + m > mid) {
                curSum = m;
                subArrays++;
            } else {
                curSum += m;
            }
            //cout<<curSum<<" ";
        }
        subArrays++;
        /*cout<<endl;
        cout<<"Left: "<<left<<endl;
        cout<<"Right: "<<right<<endl;
        cout<<"Mid: "<<mid<<endl;
        cout<<"Subarrays: "<<subArrays<<endl;*/
        if (subArrays <= k) { // answer is in [left, mid]
            right = mid;
        } else { // answer is in [mid + 1, right]
            left = mid + 1;
        }
    }
    cout<<right<<endl;
}
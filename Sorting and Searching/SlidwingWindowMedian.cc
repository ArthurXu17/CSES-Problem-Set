#include <bits/stdc++.h>

using namespace std;

void solveEven(vector<int>& nums, int k, vector<int>& sorted) {
    assert(k % 2 == 0);
    multiset<int> left(sorted.begin(), sorted.begin() + k / 2);
    multiset<int> right(sorted.begin() + k / 2, sorted.begin() + k);
    auto it = left.end();
    it--;
    cout<<*it<<" ";
    int n = nums.size();
    for (int i = k; i < n; i++) {
        int remove = nums[i - k];
        int add = nums[i];
        it = left.find(remove);
        if (it != left.end()) {
            left.erase(it);
            auto rightMinIt = right.begin();
            if (add < *rightMinIt) {
                left.insert(add);
            } else {
                left.insert(*rightMinIt);
                right.erase(rightMinIt);
                right.insert(add);
            }
        } else {
            it = right.find(remove);
            right.erase(it);
            auto leftMaxIt = left.end();
            leftMaxIt--;
            if (add > *leftMaxIt) {
                right.insert(add);
            } else {
                right.insert(*leftMaxIt);
                left.erase(leftMaxIt);
                left.insert(add);
            }
        }
        it = left.end();
        it--;
        cout<<*it<<" ";
    }
    cout<<endl;
}

void solveOdd(vector<int>& nums, int k, vector<int>& sorted) {
    if (k == 1) {
        for (auto & m : nums) {
            cout<<m<<" ";
        }
        cout<<endl;
        return;
    }
    assert(k % 2 == 1);
    multiset<int> left(sorted.begin(), sorted.begin() + k / 2);
    multiset<int> right(sorted.begin() + k / 2 + 1, sorted.begin() + k);
    int middle = sorted[k / 2];
    cout<<middle<<" ";
    int n = nums.size();
    // adding nums[i] to window
    for (int i = k; i < n; i++) {
        int remove = nums[i - k];
        int add = nums[i];
        if (middle == remove) {
            if (add > middle) {
                right.insert(add);
                auto it = right.begin();
                int newMiddle = *it;
                right.erase(it);
                middle = newMiddle;
            } else if (add < middle) {
                left.insert(add);
                auto it = left.end();
                it--;
                int newMiddle = *it;
                left.erase(it);
                middle = newMiddle;
            }
            // if add = middle = remove, nothing happens
        } else if (remove < middle) {
            auto removeIt = left.find(remove);
            left.erase(removeIt);
            if (add <= middle) {
                left.insert(add);
            } else {
                // rebalance, middle gets added to left, add add to right, middle = min(right)
                left.insert(middle);
                right.insert(add);
                auto it = right.begin();
                int newMiddle = *it;
                right.erase(it);
                middle = newMiddle;
            }
        } else if (remove > middle) {
            auto removeIt = right.find(remove);
            right.erase(removeIt);
            if (add >= middle){
                right.insert(add);
            } else {
                // rebalance, middle gets added to right, add add to left, middle = max(left)
                right.insert(middle);
                left.insert(add);
                auto it = left.end();
                it--;
                int newMiddle = *it;
                left.erase(it);
                middle = newMiddle;
            }
        }
        cout<<middle<<" ";
    }
    cout<<endl;
}

int main() {
    int n, k, x;
    cin>> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.begin() + k);
    if (k % 2) {
        solveOdd(nums, k, sorted);
    } else {
        solveEven(nums, k, sorted);
    }

}
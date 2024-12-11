#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    if (n == 1) {
        cout<<"1"<<endl;
        return 0;
    } 
    set<int> nums;
    for (int i = 1; i <= n; i++) {
        //cout<<"Inserting into nums: "<<i<<endl;
        nums.insert(i);
    }
    // iteratively remove number and find number that is bigger than it
    //cout<<"Size: "<<nums.size()<<endl;
    int removeNumber = 2;
    while (nums.size() >= 2) {
        //cout<<"Remaining Size: "<<nums.size()<<endl;
        nums.erase(removeNumber);
        //cout<<"Hello world"<<endl;
        cout<<removeNumber<<" ";
        auto nextBiggerNumberIt = nums.upper_bound(removeNumber);
        if (nextBiggerNumberIt == nums.end()) {
            nextBiggerNumberIt = nums.begin();
        }
        nextBiggerNumberIt++;
        if (nextBiggerNumberIt == nums.end()) {
            nextBiggerNumberIt = nums.begin();
        }
        removeNumber = *nextBiggerNumberIt;
        //cout<<"End of current iteration on size: "<<nums.size()<<endl;
    }
    cout<<removeNumber<<endl;

}
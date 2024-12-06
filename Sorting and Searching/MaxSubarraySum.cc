#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    int n;
    cin >>n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    ll curSum = 0;
    ll maxSum = INT_MIN;
    for (int i = 0; i < n ; i++) {
        if (curSum <= 0) {
            curSum = arr[i];
        } else {
            curSum += arr[i];
        }
        maxSum = max(curSum, maxSum);
    }
    cout<<maxSum<<endl;
}
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
    sort(arr.begin(), arr.end());
    int median = arr[arr.size() / 2];
    long long result = 0;
    for (auto & num : arr) {
        result += abs(median - num);
    }
    cout<<result<<endl;
}
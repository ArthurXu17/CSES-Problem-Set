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
    ll curSum = 0;
    // assume arr[0] = 1
    for (auto & n : arr) {
        if (n >= curSum + 2) {
            cout<<curSum + 1<<endl;
            return 0;
        } else {
            curSum += n;
        }
    }
    cout<<curSum + 1<<endl;

}
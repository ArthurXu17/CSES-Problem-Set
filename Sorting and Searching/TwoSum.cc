#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum;
    cin >>n >> sum;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    map<int, int> indices;
    for (int i = 0; i < n ; i++) {
        int num = arr[i];
        if (indices.find(sum-num) != indices.end()) {
            cout<<indices[sum-num] + 1<<" "<<i + 1<<endl;
            return 0;
        } 
        indices[num] = i;
    }
    cout<<"IMPOSSIBLE"<<endl;
}
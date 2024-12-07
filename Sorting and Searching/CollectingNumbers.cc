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
    vector<bool> seen(n+1, false); // arr[i] is whether or not i has been seen yet or not
    int numBehind = 0;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        if (num != n && seen[num + 1]) {
            numBehind++;
        }
        seen[num] = true;
    }
    cout<<numBehind + 1<<endl;

}
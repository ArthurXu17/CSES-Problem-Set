#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> intervals; // [finish, start]
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.emplace_back(end, start);
    }
    sort(intervals.begin(), intervals.end());
    int count = 1;
    int curEnd = intervals[0].first;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].second >= curEnd) {
            curEnd = intervals[i].first;
            count++;
        }
    }
    cout<<count<<endl;
}
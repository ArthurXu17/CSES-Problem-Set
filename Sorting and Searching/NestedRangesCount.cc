#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;
int main() {
    int n;
    cin >>n;
    vector<p> intervals;
    map<p, int> intervalIndex;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        auto interval = make_pair(x,y);
        intervals.emplace_back(interval);
        intervalIndex[interval] = i;
    }
    sort(intervals.begin(), intervals.end(), [](p a, p b) {
        if (a.first < b.first) {
            return true;
        } else if (b.first < a.first) {
            return false;
        } else {
            return a.second >= b.second;
        }
    });
    vector<int> contains(n, 0);
    vector<int> isContained(n, 0);
    set<int> endTimes;
    endTimes.insert(intervals.back().second);
    int minEnd = intervals.back().second;
    for (int i = n - 2; i >= 0; i--) {
        auto interval = intervals[i];
        if (interval.second >= minEnd) {
            contains[intervalIndex[interval]] = 1;
        }
        minEnd = min(interval.second, minEnd);
    }
    int maxEnd = intervals[0].second;
    for (int i = 1; i < n; i++) {
        auto interval = intervals[i];
        if (interval.second <= maxEnd) {
            isContained[intervalIndex[interval]] = 1;
        }
        maxEnd = max(interval.second, maxEnd);
    }
    for (auto & b : contains) {
        cout<<b<<" ";
    }
    cout<<endl;
    for (auto & b : isContained) {
        cout<<b<<" ";
    }
    cout<<endl;

    /*
    for (auto & q : intervals) {
        cout<<q.first<<" "<<q.second<<endl;
    }*/

}
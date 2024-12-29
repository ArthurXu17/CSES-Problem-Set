#include <ext/pb_ds/assoc_container.hpp> 
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using multi_set = tree<std::pair<T, int>, null_type, std::less<std::pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;


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
    multi_set<int> endTimes;
    endTimes.insert({intervals.back().second, endTimes.size()});
    for (int i = n - 2; i >= 0; i--) {
        auto interval = intervals[i];
        int position = endTimes.order_of_key({interval.second, INT_MAX});
        contains[intervalIndex[interval]] = position;
        endTimes.insert({interval.second, endTimes.size()});
    }
    endTimes = {};
    assert(endTimes.size() == 0);
    endTimes.insert({intervals.front().second, endTimes.size()});
    for (int i = 1; i < n; i++) {
        auto interval = intervals[i];
        int position = endTimes.order_of_key({interval.second, INT_MIN});
        isContained[intervalIndex[interval]] = endTimes.size() - position;
        endTimes.insert({interval.second, endTimes.size()});
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
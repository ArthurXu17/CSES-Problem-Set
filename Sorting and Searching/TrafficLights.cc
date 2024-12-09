#include <bits/stdc++.h>

using namespace std;

void addDistance(map<int, int>& distances, int distance) {
    if (distances.find(distance) == distances.end()) {
        distances[distance] = 1;
    } else {
        distances[distance]++;
    }
}

int main() {
    int n,x;
    cin >>x>>n;
    map<int, int> distances = {{x, 1}};
    set<int> lights = {0,x};

    for (int i = 0; i < n; i++) {
        int location;
        cin>>location;
        auto location_it = lights.upper_bound(location);
        int nextLight = *location_it;
        location_it--;
        int prevLight = *location_it;
        int rightDist = nextLight - location;
        int leftDist = location - prevLight;
        addDistance(distances,leftDist);
        addDistance(distances,rightDist);
        int oldDist = nextLight - prevLight;
        if (distances[oldDist] == 1) {
            distances.erase(oldDist);
        } else {
            distances[oldDist]--;
        }
        auto biggestDistanceIt = distances.rbegin();
        cout<<(*biggestDistanceIt).first<<" ";
        
        lights.insert(location);
    }
    cout<<endl;

}
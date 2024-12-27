#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> assignedColours(n, 0);
    // need starts to always come before end since interval can have length 0
    vector<array<int, 3>> times; // times[0\ is time, times[1] = 1 if end, 0 if start, times[2] is the original interval it pertains to
    int maxColourUsed = 0;
    set<int> availableColours;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        times.push_back({a, 0, i});
        times.push_back({b, 1, i});
    }
    sort(times.begin(), times.end());
    for (auto & t : times) {
        int time = t[0];
        if (t[1] == 0) { // start
            if (availableColours.empty()) {
                // use new colour
                maxColourUsed++;
                int newColour = maxColourUsed;
                assignedColours[t[2]] = newColour;
            } else {
                // use old colour
                int newColour = *(availableColours.begin());
                availableColours.erase(newColour);
                assignedColours[t[2]] = newColour;
            }
        } else { // end
            int assignedColour = assignedColours[t[2]];
            availableColours.insert(assignedColour);
        }
    }
    cout<<maxColourUsed<<endl;
    for (auto & c : assignedColours) {
        cout<<c<<" ";
    }
    cout<<endl;
}
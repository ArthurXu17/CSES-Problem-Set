#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >>n;
    map<int,int> towerBases;

    for (int i = 0; i < n; i++) {
        int cubeSize;
        cin>>cubeSize;
        auto it = towerBases.upper_bound(cubeSize);
        if (it == towerBases.end()) {
            // new tower
            if (towerBases.count(cubeSize)) { // in case smallest cube happens to be cubeSize
                towerBases[cubeSize]++;
            } else {
                towerBases[cubeSize] = 1;
            }
        } else {
            int chosenBase = (*it).first;

            // remove one base of Size chosenBase
            if (towerBases[chosenBase] == 1) {
                towerBases.erase(chosenBase);
            } else {
                towerBases[chosenBase]--;
            }

            // add cube Size to bases
            if (towerBases.count(cubeSize)) {
                towerBases[cubeSize]++;
            } else {
                towerBases[cubeSize] = 1;
            }
        }
    }
    int result = 0;
    for (auto & [_, v]: towerBases) {
        result += v;
    }
    cout<<result<<endl;

}
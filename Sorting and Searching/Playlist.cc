#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >>n;
    vector<int> songs;
    map<int,int> songIndices;
    int currentLength = 0;
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        maxLength = max(currentLength, maxLength);
        int song;
        cin>>song;
        if (songIndices.find(song) == songIndices.end() || songIndices[song] < i - currentLength) {
            currentLength++;
        } else {
            currentLength = i - songIndices[song];
        }
        songIndices[song] = i;
        maxLength = max(currentLength, maxLength);
    }
    cout<<maxLength<<endl;

}
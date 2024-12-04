#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main(){
    string str;
    cin>>str;
    int sum = 0;
    sort(str.begin(), str.end());
    do {
        sum++;  
    } while (next_permutation(str.begin(), str.end()));
    cout<<sum<<"\n";
    sort(str.begin(), str.end());
    do {
        cout<<str<<"\n";
    } while (next_permutation(str.begin(), str.end()));

}
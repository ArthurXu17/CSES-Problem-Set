#include <bits/stdc++.h>

#define ll long long

using namespace std;

void recurse(int sizeoftower, int start, int end){
    if(sizeoftower == 1){
        cout<<start<<" "<<end<<"\n";
    }
    else{
        recurse(sizeoftower-1, start, 6-start-end);
        cout<<start<<" "<<end<<"\n";
        recurse(sizeoftower-1, 6-start-end,end);
    }
}

int recursecount(int sizeoftower, int start, int end){
    int result = 0;
    if(sizeoftower == 1){
        result++;
    }
    else{
        result+= recursecount(sizeoftower-1, start, 6-start-end)+recursecount(sizeoftower-1, 6-start-end,end)+1;
    }
    return result;
}

int twopower(int n){
    int result = 1;
    for(int i = 0; i < n; i++){
        result = result*2;
    }
    return result;
}

int main(){
    /*int n;
    cin>>n;
    cout<<recursecount(n,1,3)<<"\n";
    recurse(n,1,3);*/
    for (int i = 1; i < 10; i++){
        cout<<i<<" "<<recursecount(i,1,3)<<" "<< twopower(i) - 1<<"\n";
    }
}
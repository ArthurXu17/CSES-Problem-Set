#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n,max;
    cin>>n;
    cin>>max;
    ll gondolas = 0;
    ll weights[n];
    for(int i = 0; i < n; i++){
        cin>>weights[i];
    }
    sort(weights, weights + sizeof(weights)/sizeof(weights[0]));

    ll left = 0;
    ll right = n-1;
    
    while(left <= right){
        if(weights[left] + weights[right] <= max){
            left++;
            right--;
        }
        else{
            right--;
        }
        gondolas++;
    }
    cout<<gondolas;

}
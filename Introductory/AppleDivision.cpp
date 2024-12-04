#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr, arr + sizeof(arr)/sizeof(arr[0]));
    ll mindiff = 10e10;
    if(n == 1){
        cout<<arr[0];
    }
    else{
        //go through all combinations
        for(ll combinationsize = 1; combinationsize <= n/2; combinationsize++){
            //generate all permutations of the size;
            string permutationGenerator = "";
            for(ll i = 1; i <=combinationsize; i++){
                permutationGenerator+='0';
            }
            for(ll i = 1; i <= n - combinationsize; i++){
                permutationGenerator+='1';
            }
            //cout<<permutationGenerator<<"\n";
            do{
                ll tempsum = 0;
                for(ll j = 0; j < n; j++){
                    if(permutationGenerator[j] == '0'){
                        tempsum+=arr[j];
                        //cout<<arr[j]<<" ";
                    }
                }
                ll diff = abs(2*tempsum-sum); 
                if(diff < mindiff){
                    mindiff = diff;
                }
            }while(next_permutation(permutationGenerator.begin(), permutationGenerator.end()));
        }
        cout<<mindiff;
    }
    
}
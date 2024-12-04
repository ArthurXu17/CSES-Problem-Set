#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    ll ans = 1;
    ll M = 1000000007; 
    for(int i = 1; i <= n; i++){
        ans = 2*ans%M;
    }
    cout<<ans<<"\n";
}
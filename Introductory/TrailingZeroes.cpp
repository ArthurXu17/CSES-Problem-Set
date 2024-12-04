#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

ll pow (ll base, ll exponent){
    ll ans = 1;
    for(int i = 0; i < exponent;i++){
        ans = ans*ans;
    }   
    return ans;
}

int main(){
    ll n;
    cin>>n;
    ll power = 1;
    ll ans = 0;
    while(pow(5,power) <= n){
        ans += n/pow(5,power);
        power++;
    }
    cout<<ans;
}
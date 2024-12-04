#include <bits/stdc++.h>

#define ll long long

using namespace std;
ll pow10(ll n){
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans = 10*ans;
    }
    return ans;
}

int main(){
    int q;
    cin>>q;
    for(int counter = 0 ; counter < q; counter++){
        ll n;
        cin>>n;
        ll digits = 0;
        if(n > 9){
            do{
                digits++;
                n-=9*digits*pow10(digits-1);
            }while (n > 9*(digits+1)*pow10(digits)); 
            
            ll ans = (n/(digits+1));
            ll remainder;
            if(n%(digits+1) == 0){
                remainder = digits+1;
                ans--;
            }
            else{
                remainder = n%(digits+1);
            }
            ll reference = pow10(digits) + ans;
            string str = to_string(reference);
            cout<<str[remainder-1]<<"\n";
        }
        else{
            cout<<n<<"\n";
        }
    }
}
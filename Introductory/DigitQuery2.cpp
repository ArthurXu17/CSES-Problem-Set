#include <bits/stdc++.h>

#define ll long long

using namespace std;



int main(){
    int q;
    cin>>q;
    for(int counter = 0 ; counter < q; counter++){
       ll n;
       cin>>n;
       ll digits = 0;
       if(n>9){
           do{
                digits++;
                n-=9*digits*pow(10,digits-1);
            }while (n > 9*(digits+1)*pow(10,digits));

            ll integersBefore;
            ll remainder;
            integersBefore = n/(digits+1);
            remainder = n%(digits+1);
            if(remainder == 0){
                remainder = digits+1;
                integersBefore--;
            }
            ll reference = pow(10,digits) + integersBefore;
            string str = to_string(reference);
            cout<<n<<" "<<digits<<" "<<integersBefore<<" "<<remainder<<" "<<reference<<" ";
            cout<<str[remainder-1]<<"\n";
       }
       else{
           cout<<n<<"\n";
       }
       
    }
}
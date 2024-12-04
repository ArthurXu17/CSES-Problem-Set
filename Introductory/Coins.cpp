#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        ll a,b;
        cin>>a;
        cin>>b;
        if( (a+b)%3 != 0){
            cout<<"NO"<<"\n";
        }
        else{
            if(a > 2*b){
                cout<<"NO"<<"\n";
            }
            else if(b > 2*a){
                cout<<"NO"<<"\n";
            }
            else{
                cout<<"YES"<<"\n";
            }
        }
    }
}
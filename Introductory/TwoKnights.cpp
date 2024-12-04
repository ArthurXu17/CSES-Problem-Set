#include <iostream>
#include <cmath>



using namespace std;

int main(){
    unsigned long long n;
    cin>>n;
    cout<<0<<"\n";
    for(unsigned long long k = 2; k<=n;k++){
        unsigned long long ans = k*k*(k*k-1)/2-4*(k-1)*(k-2);
        cout<<ans<<"\n";
    }
}
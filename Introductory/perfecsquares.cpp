#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
 
bool isPerfectSquare(ll x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
 
int main()
{
    ll counter = 0;
		for(ll i = 1; i < 3768000; i++) {
			if(isPerfectSquare(37680*i)) {
				counter++;
				cout<<i<<"\n";
			}
		}
        cout<<counter;
    
}
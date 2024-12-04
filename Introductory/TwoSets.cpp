#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%4 == 0){
        cout<<"YES"<<"\n";
		cout<<n/2<<"\n";	
		for(int i = n/4+1; i <= 3*n/4; i++) {
			cout<<i<<" "; 
		}
		cout<<n/2<<"\n";
		for(int i = 1; i <= n/4; i++) {
			cout<<i<<" "; 
		}
		for(int i = 3*n/4+1; i <= n; i++) {
			cout<<i<<" "; 
		}
    }
    else if (n%4 == 3){
        cout<<"YES"<<"\n";
        cout<<n/2<<"\n";
        for(int i = 1; i <= n/4; i++){
            cout<<i<<" "; 
        }
        for(int i = n-n/4; i <=n; i++){
            cout<<i<<" ";
        }
        cout<<n/2 + 1<<"\n";
        for(int i = n/4+1; i < n - n/4 ; i++){
            cout<<i<<" "; 
        }
    }
    else{
        cout<<"NO";
    }
}
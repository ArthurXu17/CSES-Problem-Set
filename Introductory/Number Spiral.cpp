#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
		for(int i = 0; i < t; i++) {
			long x,y;
            cin>>y;
			cin>>x;
			long ans;
			if(x > y) {
				if(x%2 == 0) {
					ans = (x-1)*(x-1)+y;
				}
				else {
					ans = x*x-y+1;
				}
			}
			else {
				if(y%2 == 0) {
					ans = y*y - x + 1;
				}
				else {
					ans = (y-1)*(y-1) + x;
				}
			}
			cout<<ans<<"\n";
		}
	
}
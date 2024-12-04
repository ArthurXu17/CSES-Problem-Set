#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
    ll applicants[n];
    ll apartments[m];
    for(int i = 0; i < n; i++){
        cin>>applicants[i];
    }
    for(int i = 0; i < m; i++){
        cin>>apartments[i];
    }
    sort(applicants, applicants + sizeof(applicants)/sizeof(applicants[0]));
    sort(apartments, apartments + sizeof(apartments)/sizeof(apartments[0]));

    ll matches = 0;
    ll topcounter = 0;
    ll bottomcounter = 0;
    while(topcounter < n && bottomcounter < m){
        if(abs(applicants[topcounter] - apartments[bottomcounter]) <= k){
            matches++;
            topcounter++;
            bottomcounter++;
        }
        else if(applicants[topcounter] - apartments[bottomcounter] > k){//top too big
            bottomcounter++;
        }else{//bottom too big
            topcounter++;
        }
    }
    cout<<matches;   
}
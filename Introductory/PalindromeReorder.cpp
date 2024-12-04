#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main(){
    string str;
    cin>>str;
    int n = str.length();
    int letterCount[26];
    for(int i = 0; i < 26; i++){
        letterCount[i] = 0;
    }
    for(int i = 0; i < str.length(); i++){
        int ascii = (int) str[i];
        letterCount[ascii-65]++;
    }

    int nooc = 0;//numberOfOddCounts
    char odd;
    for(int i = 0; i <= 25; i++){
        if(letterCount[i] % 2 == 1){
           nooc++;
           odd = (char) (i+65);
        }
        //cout<<(char) (i+65)<<" "<<letterCount[i]<<"\n";
    }
    //cout<<nooc<<"\n";


    if(nooc <= 1){
        if(n %2 == 0){
            if(nooc == 1){
                cout<<"NO SOLUTION";
            }
            else{
                int counter = 0;
                for(int i = 0; i <=25; i++){
                    for(int j = 0; j < letterCount[i]/2; j++){
                        str[counter] = (char) (i+65);
                        str[n-counter-1] = (char) (i+65);
                        counter++;
                        //cout<<str<<" TEST "<<"\n";
                    }
                }
                cout<<str;
            }
        }
        else{
            if(nooc == 0){
                cout<<"NO SOLUTION";
            }
            else{
                int counter = 0;
                str[n/2] = odd;
                for(int i = 0; i <=25; i++){
                    for(int j = 0; j < letterCount[i]/2; j++){
                        str[counter] = (char) (i+65);
                        str[n-counter-1] = (char) (i+65);
                        counter++;
                        //cout<<str<<" TEST "<<"\n";
                    }
                }
                cout<<str;
            }
        }
    }
    else{
        cout<<"NO SOLUTION";
    }
}
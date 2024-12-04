#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    char board[8][8];
    int takenSquareCount = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin>>board[i][j];
        }
    }
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == '*'){
                takenSquareCount++;
            }
        }
    }

    char takenSquares[takenSquareCount][2];
    int counter = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == '*'){
                takenSquares[counter][0] = i;
                takenSquares[counter][1] = j;
                counter++;
            }
        }
    }
    string str = "01234567";
    //the index represents the x coordinate
    //the actual value at the index represents the y coordinate
    //all permutations of this string represents all the ways to put queens on a chess board such that they share no rows or columns
    ll ans = 0;
    ll totalCases = 0;
    do{
        int forwardDiag[15];
        int backwardDiag[15];
        for(int i = 0; i < 15; i++){
            forwardDiag[i] = 0;
        }
        for(int i = 0; i < 15; i++){
            backwardDiag[i] = 0;
        }
        for(int index = 0; index <= 7; index++){
            int value = (int)(str[index]) - 48;
            int diff = index - value; //diff range is -7 to 7
            int sum = index + value; //sum range is 0 to 14
            forwardDiag[diff + 7]++;
            backwardDiag[sum]++;
        }
        bool endLoop = true;
        //checks to see that none are on the same diagonal
        for(int j = 0; j < 15; j++){
            if(forwardDiag[j] >= 2 || backwardDiag[j] >= 2){
                endLoop = false;
            }
        }
        //checks if any of the queens are on taken squares
        if(endLoop == true){//only check if already certain that none are on the same diagonal
            for(int index = 0; index <= 7; index++){
                for(int i = 0; i < takenSquareCount; i++){
                    int yvalue = (int)(str[index]) - 48;
                    if(index == takenSquares[i][0] && yvalue == takenSquares[i][1]){
                        endLoop = false;
                        index = 8;//break big loop
                        break;//break small loop
                    }
                }
            }
        }
        if(endLoop == true){
            ans++;
        }
    }while(next_permutation(str.begin(), str.end()));
    /*cout<<takenSquareCount<<"\n";
    for(int i = 0; i < takenSquareCount; i++){
        cout<<takenSquares[i][0]<<" "<<takenSquares[i][1]<<"\n";
    }*/
    cout<<ans;
}
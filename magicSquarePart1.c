#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void magicSquareCheck(int square[3][3]);


int main(){

    int magicSquare[3][3] = {{4,9,2}, {3,5,7} , {8,1,6}};
    int regularSquare[3][3] = {{1,2,3}, {4,5,6}, {7,8,9} };

    magicSquareCheck(magicSquare);
    magicSquareCheck(regularSquare);
    return 0;
}












void magicSquareCheck(int square[3][3]){
    int sum = square[1][0] + square[1][1] + square[1][2];
    bool fail = false;

    //checking rows
    for(int row = 0; row < 3; row++){
        if(sum != square[row][0] + square[row][1] + square[row][2]){
            fail = true;
        } 
    }
    //checking columns 
    if(!fail){
        for(int colm = 0; colm < 3; colm++){
            if(sum != square[0][colm] + square[1][colm] + square[2][colm]){
                fail = true;
            }
        } 
    }
    //checking diagonals
    if(!fail){
        if(sum != square[0][0] + square[1][1] + square[2][2]){
            fail = true;
        }
        if(sum != square[0][2] + square[1][1] + square[2][0]){
            fail = true;
        }
    }

    if(fail){
        return 0;
    }else{
        return 1;
    }
}


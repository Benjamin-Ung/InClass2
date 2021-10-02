#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool magicSquareCheck(int square[3][3]);
void magicSquareGenerator(int square[3][3]);


int main(){
    time_t t;
    srand((unsigned) time(&t));

    int count = 0;
    int square[3][3] = { {0,0,0},{0,0,0},{0,0,0}};
    bool found = false;


    while(!found){
        magicSquareGenerator(square);
        found = magicSquareCheck(square);
        count++;
        //printf("%d\n", count);
    }
        
    printf("It took %d tries to get a Lo Shu Magic Square\n", count);
    printf("[%d][%d][%d]\n", square[0][0],square[0][1], square[0][2]);
    printf("[%d][%d][%d]\n",square[1][0],square[1][1], square[1][2]);
    printf("[%d][%d][%d]\n\n",square[2][0],square[2][1], square[2][2]);
}

void magicSquareGenerator(int square[3][3]){
    int value = 0;
    int num[] = {1,2,3,4,5,6,7,8,9};
    bool found = false;
    int numTracker = 0;

    //Init random number generator
    
    for(int row = 0; row < 3; row++){
        for(int colm = 0; colm < 3; colm++){
            //check if it is repeated value
            while(!found){
                value = (rand() % 9) + 1;
                found = false;
                for(int i = 0; i < 9;i++){
                    //printf("%d   %d\n", num[i], value);
                    if(num[i] == value){
                        found = true;
                    }
                }
            }
            //if not repeated value, insert it
            square[row][colm] = value;
            num[value - 1] = 0;
            found = false;
        }
    }
}




bool magicSquareCheck(int square[3][3]){
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

    return !fail;
}


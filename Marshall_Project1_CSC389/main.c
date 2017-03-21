//
//  main.c
//  Marshall_Project1_CSC389
//
//  Created by Chloe Marshall on 3/20/17.
//  Copyright © 2017 Chloe Marshall. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//int argc, const char * argv[]

int main() {
    int ranPlayerNum, ranGuessNum, userInputPlayerNum;
    char userInputGuessOrPass[5];
    srand((unsigned)time(NULL));
    ranPlayerNum = (rand() % 2) + 1;
    ranGuessNum = (rand() % 10) + 1;
    int turnArray[15] = {0};
    int turn = 0;
    bool win = false;
    
    
    struct Players {
        int timesPassed;
        int consecTimesPassed;
        int playerNumber;
    };
    
    struct Players p1;
    struct Players p2;
    p1.playerNumber = 1;
    p2.playerNumber = 2;
    
    p1.consecTimesPassed = 0;
    p2.consecTimesPassed = 0;
    p1.timesPassed = 0;
    p2.timesPassed = 0;

    do {
        printf("Enter your player number (1 or 2)\n");
        scanf("%d", &userInputPlayerNum);
        if (userInputPlayerNum != ranPlayerNum) {
            printf("You have to wait your turn\n");
        }
        else{
                break;
        }
    } while (ranPlayerNum != userInputPlayerNum);
    
    
    do {
    printf("Player %d: enter your guess (1-10) or type 'pass' to pass the turn to next player\n", ranPlayerNum);
    scanf("%s", userInputGuessOrPass);
        
    
    int userInputGuessINT = atoi(userInputGuessOrPass);
    
    if (strcmp(userInputGuessOrPass, "pass") == 0 && userInputGuessINT == 0){
        if(ranPlayerNum == p1.playerNumber){
            if(p1.timesPassed >= 3){
                printf("You have exceeded the number of times you may pass this game, please guess a number\n");
                ranPlayerNum = 1;
            }else if (p1.timesPassed <= 3){
                p1.consecTimesPassed++;
                if (p1.consecTimesPassed >= 2){
                    
                    printf("You may not pass two times in a row\n");
                    ranPlayerNum = 1;
                }
                else {
                turnArray[turn] = p1.playerNumber;
                turn++;
                p1.timesPassed++;
                printf("You have passed %d time(s), you have %d more time(s) left\n\n", p1.timesPassed, (3-p1.timesPassed) );
                ranPlayerNum = 2;
                }
                
            }
        }else if(ranPlayerNum == p2.playerNumber){
            if(p2.timesPassed >= 3){
                printf("You have exceeded the number of times you may pass this game, please guess a number\n");
                ranPlayerNum = 2;
            }else if (p2.timesPassed <= 3){
                p2.consecTimesPassed++;
                if (p2.consecTimesPassed >= 2){
                    printf("You may not pass two times in a row\n");
                    ranPlayerNum = 2;
                }
                else{
                turnArray[turn] = p2.playerNumber;
                turn++;
                p2.timesPassed++;
                printf("You have passed %d time(s), you have %d more time(s) left\n\n", p2.timesPassed, (3-p2.timesPassed) );
                ranPlayerNum = 1;
                }
                
            }
        }
    }else if (strcmp(userInputGuessOrPass, "pass") != 0 && userInputGuessINT == 0){
        printf("Invalid entry, please try again!");
    }else if(userInputGuessINT == ranGuessNum){
        printf("Player %d, you have guessed correctly!\n Game Over\n", ranPlayerNum);
        win = true;
    }else if(userInputGuessINT > ranGuessNum){
        printf("Player %d, the number is lower, your turn is over\n", ranPlayerNum);
        if (ranPlayerNum == 1) {
            p1.consecTimesPassed = 0;
            ranPlayerNum = 2;
        }else{
            p2.consecTimesPassed = 0;
            ranPlayerNum = 1;
        }
    }else if (userInputGuessINT < ranGuessNum){
        printf("Player %d, the number is higher, your turn is over\n", ranPlayerNum);
        if (ranPlayerNum == 1) {
            p1.consecTimesPassed = 0;
            ranPlayerNum = 2;
        }else{
            p2.consecTimesPassed = 0;
            ranPlayerNum = 1;
        }
    }
    
    } while (!win);
    
    

    
    
}

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
    //create array to hold user input, 5 characters should be enough since pass is only 4 characters
    char userInputGuessOrPass[5];
    //generate truly random number by seeding it according to the computer's time
    srand((unsigned)time(NULL));
    //generate random number between 1 and 2 to start the game
    ranPlayerNum = (rand() % 2) + 1;
    //generate random guessable number for either player 1 or 2 to guess at during the game
    ranGuessNum = (rand() % 10) + 1;
    bool win = false;
    
    //initilize struct to hold variables associated with each player
    struct Players {
        int timesPassed; //this variable will be incremented each time a player types pass
        int consecTimesPassed; //this variable will be incremented each time a player presses pass and 0'd whenever they make a guess
        int playerNumber; //this variable will hold the player number, in this case 1 or 2
    };
    
    struct Players p1;
    struct Players p2;
    p1.playerNumber = 1;
    p2.playerNumber = 2;
    
    p1.consecTimesPassed = 0;
    p2.consecTimesPassed = 0;
    p1.timesPassed = 0;
    p2.timesPassed = 0;

    //do-while loop asks for player number, if the player's number does not match the randomly generate player number, they will be notified that they have to wait their turn, the loop will continue until the correct player enters their number, at which point the loop will be broken out of
    do {
        printf("Enter your player number (1 or 2)\n");
        scanf("%d", &userInputPlayerNum);
        if(userInputPlayerNum > 2 || userInputPlayerNum < 1){
            printf("Invalid Entry, please try again\n");
        }else if (userInputPlayerNum != ranPlayerNum) {
            printf("You have to wait your turn\n");
        }
        
    } while (ranPlayerNum != userInputPlayerNum);
    
    //This do-while loop continues to run until the game is won (win = true), which will only be when either player guesses the correct number.
    
    
    //ranPlayerNum is then changed to the opposite player
    
    
    do {
    printf("Player %d: enter your guess (1-10) or type 'pass' to pass the turn to next player\n", ranPlayerNum);
    scanf("%s", userInputGuessOrPass);
        
    //Assigns an integer value of the user input to the variable userInputGuessINT, so that if the user does enter a number, it can be directly compared to the randomly generated guessable number
    int userInputGuessINT = atoi(userInputGuessOrPass);
        
    //If the user types pass into the prompt, the loop checks which player has entered the pass by checking which player was allowed to continue, this value must equal ranPlayerNum by default during the first turn of the game. Depending on whether the player was 1 or 2, will depend on which if statement will be executed
    if (strcmp(userInputGuessOrPass, "pass") == 0 && userInputGuessINT == 0){
        if(ranPlayerNum == p1.playerNumber){
            //If the user has entered "pass" more than 3 non-consecutive times during the game, they are notified with the following printf() function and ranPlayerNum remains the same, which will reprompt the same user to guess again
            if(p1.timesPassed >= 3){
                printf("You have exceeded the number of times you may pass this game, please guess a number\n");
                ranPlayerNum = 1;
            }else if (p1.timesPassed <= 3){
                p1.consecTimesPassed++;
                //If (object).consecTimesPassed is greater than or equal to 2, the player is notified with the followinf printf() function and ranPlayerNum remains the same, thus the loop will reprompt the same player to guess again
                if (p1.consecTimesPassed >= 2){
                    
                    printf("You may not pass two times in a row\n");
                    ranPlayerNum = 1;
                }
                //If the player has less than the number of passes allowed for the duration of the game (3) and has not consecutively inputted pass, (object).timesPassed is incremented and (object).consecTimesPassed is incremented and they are notified how many times they have passed, and how many times they have left to pass.
                else {
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
                p2.timesPassed++;
                printf("You have passed %d time(s), you have %d more time(s) left\n\n", p2.timesPassed, (3-p2.timesPassed) );
                ranPlayerNum = 1;
                }
                
            }
        }
        //If user inputs any other text other than pass, they will receive an invalid entry notice and be prompted to try again.
    }else if (strcmp(userInputGuessOrPass, "pass") != 0 && userInputGuessINT == 0){
        printf("Invalid entry, please try again!\n");
        //If current player guesses the number correctly, they will be notified with the follwoing printf() function and the do-while loop condition will be set to false, breaking the loop and ending the program
    }else if(userInputGuessINT == ranGuessNum){
        printf("Player %d, you have guessed correctly!\n Game Over\n", ranPlayerNum);
        win = true;
        //If player inputs guess that is larger than ranGuessNum, the player will be notified that the number is lower, and that their turn is over. If current ranPlayerNum is 1, it will be switched to 2 in order to change turns and vice versa
    }else if(userInputGuessINT > ranGuessNum){
        printf("Player %d, the number is lower, your turn is over\n", ranPlayerNum);
        if (ranPlayerNum == 1) {
            p1.consecTimesPassed = 0;
            ranPlayerNum = 2;
        }else{
            p2.consecTimesPassed = 0;
            ranPlayerNum = 1;
        }
        //If player inputs guess that is smaller than ranGuessNum, the player will be notified that the number is higher, and that their turn is over. If current ranPlayerNum is 1, it will be switched to 2 in order to change turns and vice versa
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

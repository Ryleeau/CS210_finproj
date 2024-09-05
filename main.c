/** main.c
 * =============================================================
 * Name: Rylee Au
 * Section:  T6
 * Project:  Final Project
 * Purpose:  Create Wordle game that goes to console
 * Documentation Statement:  
 * - EI from Capt Jameson for getWord() to initialize pointers for
 *      string array and word instead of keeping it in the function, testGetDifficulty()
 * - EI from Major Sample with getGuess(). Better to save it to the 2D array in main rather than
 *      in the function
 * - EI from Dr. Weingart helped me with getWordle() in understanding the setup for the colors
 *      with 0,1,2 for bold, yellow, and green. Also helped debug
 * ============================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "finprojfuncts.h"
#include "finprojtest.h"

int main() {
    int difficulty;
    char* word = NULL;
    char** words = NULL;

    getDifficulty(&difficulty);

    words = (char**)malloc(MAX_WORDS*sizeof(char*));
    for(int i=0;i<MAX_WORDS;i++){
        words[i] = (char*) malloc((difficulty+1)*sizeof(char));
    }

    word = (char*)malloc((difficulty+1)*sizeof(char));
    word = getWord(difficulty,words,word);
    // prints the word for fast test purposes for presentation
    printf("%s\n",word); 

    for(int i=0;i<MAX_WORDS;i++){
        free(words[i]);
    }
    free(words);


    char* guess = NULL;
    guess = (char*)malloc((difficulty+1)*sizeof(char));
    char guesses[50][10];
    int count = 0;

    // saves the user input guess to an array of past guesses
    while(strcmp(word,guess)!=0){
        guess = getGuess(difficulty,guess); 
        strcpy(guesses[count],guess);
        if(count>=0){
            printf("Past guesses:\n");
            for(int i=0;i<=count;i++){
                getWordle(difficulty,word,guesses[i]);                
            }
        }
        printf("\n");
        count++;
    }

    //free mallocs
    free(word);
    free(guess);

    printf("You won!\n\n");

    //uncomment this when running tests
    // runAllTests();

    return 0;
}
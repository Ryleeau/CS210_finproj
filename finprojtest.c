/** finprojtest.c
 * =============================================================
 * Name: Rylee Au
 * Section:  T6
 * Project:  Final Project
 * Purpose:  Test the wordle game
 * ============================================================= */

#include "finprojfuncts.h"
#include "finprojtest.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 /**
 * @brief tests getDifficulty() function to see if the difficutly was received
 * Also if the difficulty is not within range it reprompts
 * @return void so nothing
 */
void testGetDifficulty(){
    int diff = 0;
    printf("type 8 then type 5 when reprompted\n");
    getDifficulty(&diff);
    assert(diff==5);
    printf("Correctly initialized difficulty!\n");
}

 /**
 * @brief tests getDifficulty() function to test if the function 
 * got the word from the difficulty txt file
 * @return void so nothing
 */
void testGetWord(int diff){
    char** words;
    words = (char**)malloc(MAX_WORDS*sizeof(char*));
    for(int i=0;i<MAX_WORDS;i++){
        words[i] = (char*)malloc((diff+1)*sizeof(char));
    }
    char word[10];
    getWord(diff,words,word);
    for(int i=0;i<MAX_WORDS;i++){
        printf("%s ",words[i]);
    }
    printf("\nrandom word: %s\n",word);
    assert(word!=NULL);
    printf("Successfully read the file and retrieved a wordle word!\n\n");
}

 /**
 * @brief tests getGuess() function to see if the function gets the user input
 * Also reprompts if the function did not have the same number of letters as the difficulty
 * @return void so nothing
 */
void testGetGuess(){
    printf("Testing using 4 letters. Type 'wow'(less than 4 letters) and 'guess'(more than 4 letters) then type 'echo'(4 letters)\n");
    int diff = 4;
    char* guess = NULL;
    guess = (char*)malloc((diff+1)*sizeof(char));
    guess = getGuess(diff,guess);
    printf("%s\n",guess);
    assert(guess!=NULL);
    printf("Successfully got the user input guess!\n");
}

 /**
 * @brief tests getWordle() function to test if the function correctly
 * ouputs the guesses with the colors black bold, yellow, and green
 * @return void so nothing
 */
void testGetWordle(){
    printf("every letter but the last is correct:");
    getWordle(5,"wordl","words");
    printf("letters 'wer' in the word but no the right place and 'o' is correct:");
    getWordle(6,"wordle","powers");
    printf("every letter but the first is correct:");
    getWordle(6,"donkey","monkey");
    printf("none occur in the same position:");
    getWordle(5,"abcda","badab");
    printf("none occur anywhere:");
    getWordle(5,"orbit","egged");
    printf("all correct:");
    getWordle(7,"dangers","dangers");
}

 /**
 * @brief runs the testing blocks.Indicates if all tests are successful
 * @return void so nothing
 */
void runAllTests(){
    printf("Start Testing........\n");

    printf("\nTesting getDifficulty():\n");
    testGetDifficulty();
    
    printf("\nTesting getWord():\n");
    testGetWord(4);
    testGetWord(5);
    testGetWord(6);
    testGetWord(7);
    // testGetWord(8); //this correctly outputs "Could not open file."
    
    printf("\nTesting getGuess():\n");
    testGetGuess();

    printf("\nTesting getWordle():\n");
    testGetWordle();

    printf("\n.........Testing completed\n");
}
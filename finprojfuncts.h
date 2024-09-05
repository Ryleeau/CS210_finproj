/** main.c
 * =============================================================
 * Name: Rylee Au
 * Section:  T6
 * Project:  Final Project
 * Purpose:  Create Wordle game that goes to console
 * ============================================================= */

#ifndef FINPROJFUNCTS_H
#define FINPROJFUNCTS_H

#define MAX_WORDS 10

/**
 * @brief gets the difficulty (number representing number of letters in word)
 * @param difficulty pointer to int value in main
 * @return nothing
 */
void getDifficulty(int* difficutly);

/**
 * @brief Gets the word with given difficulty from txt file randomly
 * @param difficulty user input difficulty(number of letters in word)
 * @param words pointer to array of strings in main
 * @param word pointer to string in main
 * @return wordle word
 */
char* getWord(int difficulty,char** words,char* word);

/**
 * @brief Gets the guess from the user 
 * @param difficulty user input difficulty(number of letters in word)
 * @param guess pointer to string in main
 * @return user input guess
 */
char* getGuess(int difficulty,char* guess);

/**
 * @brief Compares the word to be guessed and the guess 
 * (includes checkCharAnywhere() and checkCharPosition())
 * @param difficulty number of letters in word
 * @param wordle the word to be guessed
 * @param guess user input guess
 * @return nothing
 */
void getWordle(int difficulty, char wordle[],char guess[]);

#endif
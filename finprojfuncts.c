/** main.c
 * =============================================================
 * Name: Rylee Au
 * Section:  T6
 * Project:  Final Project
 * Purpose:  Create Wordle game that goes to console
 * ============================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "finprojfuncts.h"
#define MAX_WORDS 10


void getDifficulty(int* difficulty){
    int diffHolder;
    printf("Enter the number of letters in word you would like to wordle (4,5,6,7):");
    scanf("%d",&diffHolder);
    while(diffHolder!=4 && diffHolder!=5 && diffHolder!=6 && diffHolder!=7){
        printf("You did not select 4,5,6, or 7. Try again!\n");
        printf("Enter the number of letters in word you would like to wordle (4,5,6,7):");
        scanf("%d",&diffHolder);
    }
    *difficulty = diffHolder;
}

char* getWord(int difficulty, char** words, char* wordleWord){
    FILE* myFile = NULL;
    int randNum;
    
    if(difficulty==4){
        myFile = fopen("easy.txt","r");
    }else if(difficulty==5){
        myFile = fopen("normal.txt","r");
    }else if(difficulty==6){
        myFile = fopen("hard.txt","r");
    }else if(difficulty==7){
        myFile = fopen("extreme.txt","r");
    }
    if(myFile == NULL){
        printf("Could not open file.\n");
        exit(1); 
    }

    if(words==NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for(int i=0;i<10;i++){
        fscanf(myFile,"%s\n", words[i]);
    }

    //get random word from array
    srand(time(NULL));
    randNum = rand() % 10;

    strcpy(wordleWord,words[randNum]);

    fclose(myFile);

    return wordleWord;
}

char* getGuess(int difficulty,char* guess){
    char wordHolder[difficulty+1];
    printf("Enter your wordle guess with %d letters: ",difficulty);
    scanf("%s",wordHolder);
    while(strlen(wordHolder)!=difficulty){
        printf("Invalid number of letters. Try again with %d letters: ",difficulty);
        scanf("%s",wordHolder);
    }

    strcpy(guess,wordHolder);

    return guess;
}

void getWordle(int difficulty, char wordle[],char guess[]){
    char* colors = NULL;
    colors = (char*)malloc(difficulty*sizeof(char));
    //set all characters to 0
    for(int i=0;i<difficulty;i++){ 
        colors[i]='0';
    }
    for(int i=0;i<difficulty;i++){
        for(int j=0;j<difficulty;j++){
            if(wordle[i]==guess[j]){
                // 1 is yellow
                colors[j]='1'; 
            }
        }
    }
    for(int i=0;i<difficulty;i++){
        if(wordle[i]==guess[i]){
            // 2 is green
            colors[i]='2'; 
        }
    }
    for(int i=0;i<difficulty;i++){
        if(colors[i]=='0'){
            printf("\033[1m%c\033[0m",guess[i]);
        }else if(colors[i]=='1'){
            printf("\033[93m%c\033[0m",guess[i]);
        }else if(colors[i]=='2'){
            printf("\033[1;32m%c\033[0m",guess[i]);
        }
    }
    free(colors);
    printf("\n");
}
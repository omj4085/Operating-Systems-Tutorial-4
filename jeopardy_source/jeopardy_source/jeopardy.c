/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 *Paris Scasserra ID:100815670
 *Om Jariwala ID:100863065
 *Best Akinlabi ID:100837728
 *Riya Rajesh ID: 100869701
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){
  
  //tokenizes using spaces
  char *token = strtok(input, " ");
  
  token = strtok(NULL, " "); //gets rid of first word: what or who
  token = strtok(NULL, " "); //gets rid of second word: is
  
  //third word should now be the answer
  *tokens = token;
  
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players){
  
  //first to last place means descending score order
  //compare two players i and j
  for (int i=0; i<num_players-1;i++){ 
    for (int j=i+1; j<num_players; j++){
      if (players[i].score < players[j].score){ //swap players[i] and players[j]
        player temp = players[i];
        players[i] = players[j];
        players[j] = temp;
      }
    }
  } 
  
  //print ranks
  printf("Game Result: ");
  for (inti=0; i<num_players; i++){
    printf("Name: %s  Final Score: %d \n", players[i].name, players[i].score);
  }
      
}


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS]; 
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    for (int i=0; i<4; i++){
        printf("Enter first name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }
        
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}

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
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "players.h"
#include "questions.h"
#include "jeopardy.h"

// Define the consonants
#define BUFFER_LEN 256
#define QUESTION_BANK_SIZE 20  
#define SELECTED_QUESTIONS 12  

question question_bank[QUESTION_BANK_SIZE];
int selected_questions[SELECTED_QUESTIONS];

void alarm_handler(int sig) {
    printf("\nTime's up! Moving to the next question.\n");
}

void shuffle_questions() {
    srand(time(NULL));
    // Initialize the selection array 
    for (int i = 0; i < QUESTION_BANK_SIZE; i++) {
        selected_questions[i] = i;
    }
    // Shuffle the question bank
    for (int i = QUESTION_BANK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = selected_questions[i];
        selected_questions[i] = selected_questions[j];
        selected_questions[j] = temp;
    }
}

// void initialize_game() {
   // char questions_text[QUESTION_BANK_SIZE][MAX_LEN] = { /* your questions */ };
    // char answers_text[QUESTION_BANK_SIZE][MAX_LEN] = { /* your answers  */ };
    // int values[] = {100, 200, 300, 400};

    // for (int i = 0; i < QUESTION_BANK_SIZE; i++) {
        //strncpy(question_bank[i].category, categories[i % NUM_CATEGORIES], MAX_LEN - 1);
        //question_bank[i].category[MAX_LEN - 1] = '\0';
        //strncpy(question_bank[i].question, questions_text[i], MAX_LEN - 1);
        //question_bank[i].question[MAX_LEN - 1] = '\0';
        //strncpy(question_bank[i].answer, answers_text[i], MAX_LEN - 1);
        //question_bank[i].answer[MAX_LEN - 1] = '\0';
        //question_bank[i].value = values[i % 4];
      //  question_bank[i].answered = false;
    //}

  //  shuffle_questions(); // Shuffle after initializing all questions
//}

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
//void tokenize(char *input, char **tokens){
  
  //tokenizes using spaces
  //char *token = strtok(input, " ");
  
  //token = strtok(NULL, " "); //gets rid of first word: what or who
  //token = strtok(NULL, " "); //gets rid of second word: is
  
  //third word should now be the answer
  //*tokens = token;
  
//}

// Displays the game results for each player, their name and final score, ranked from first to last place
//void show_results(player *players, int num_players){
  
  //first to last place means descending score order
  //compare two players i and j
  //for (int i=0; i<num_players-1;i++){ 
    //for (int j=i+1; j<num_players; j++){
      //if (players[i].score < players[j].score){ //swap players[i] and players[j]
        //player temp = players[i];
        //players[i] = players[j];
        //players[j] = temp;
      //}
    //}
  //} 
  
  //print ranks
  //printf("Game Result: ");
  //for (int i=0; i<num_players; i++){
    //printf("Name: %s  Final Score: %d \n", players[i].name, players[i].score);
  //}
      
//}
int main(int argc, char *argv[]) {
    // An array of 4 players
    player players[NUM_PLAYERS]; 

    // Declare name buffer for player selection
    char name[BUFFER_LEN];
    
    // Input buffer and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players' names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name of player %d: ", i + 1);
        fgets(players[i].name, BUFFER_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; //remove newline character
        players[i].score = 0;  //initialize each player's score
    }

    bool game_over = false;
    int total_answered = 0; //track the total number of answered questions; when 12 questions are answered, game over


  
    // Perform an infinite loop getting command input from users until the game ends
    while (game_over == false) {
        // Call functions from the questions and players source files
        display_categories();

        //loop to check if input is correct by calling player_exists() and try again if name is invalid
        int exit_loop = 0;
        while (exit_loop == 0) { 
            printf("Enter name of selected player: ");
            char name[BUFFER_LEN];
            fgets(name, BUFFER_LEN, stdin);
            name[strcspn(name, "\n")] = '\0'; //remove newline character
            
            if (player_exists(players, NUM_PLAYERS, name) == false) {
                printf("Could not validate player. Try again.\n");
            } else {
                exit_loop = 1;
            }
        }
        
        //get the selected category and dollar amount question
        char category[BUFFER_LEN];
        int value;
        
        printf("Enter selected category: ");
        fgets(category, BUFFER_LEN, stdin);
        category[strcspn(category, "\n")] = '\0'; //remove newline character
        
        exit_loop = 0; //loop to check if question has already been answered
        while (exit_loop == 0) {
            printf("Enter selected dollar amount question: ");
            fgets(buffer, BUFFER_LEN, stdin);
            sscanf(buffer, "%d", &value); 
            
            if (already_answered(category, value) == true) {
                printf("Already answered. Pick another.\n");
            } else {
                exit_loop = 1;
            }
        }

        //display the selected question
        display_question(category, value);
        
        //ask the selected player to answer
        char answer[BUFFER_LEN];
        printf("Your answer: ");
        fgets(answer, BUFFER_LEN, stdin);
        answer[strcspn(answer, "\n")] = '\0';  
       
        //check if the answer is correct
        if (valid_answer(category, value, answer) == true) {
            printf("Correct! You earned %d points.\n", value);
            //add points to player
            update_score(players, NUM_PLAYERS, name, value);  
            total_answered++; //increment total answered questions
        } else {
            printf("Incorrect! Continuing game.\n");
        }

        //check for game's end
        if (total_answered == 12) {
            game_over = true;
        }
       
    }

    //Display final results
    show_results(players, NUM_PLAYERS);

    return EXIT_SUCCESS;
}

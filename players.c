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
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name) {
    for (int i = 0; i < num_players; i++) {
        // Ensure name is not NULL before comparing
        if (players[i].name[0] != '\0' && strcmp(players[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {  // Fixed: using 0 instead of 'o'
            players[i].score += score;
            break; // Exit loop after updating the score
        }
    }
}
//Displaying the rankings of players
void show_results(player *players, int num_players) {
    //sort the players in ascending order
    for (int i = 0; i < num_players - 1; i++){
       for (int j = i + 1; j < num_players; j++){
          if (players[i].score < players[j].score) {
             player temp = players[i];
             players[i] = players[j];
             players[j] = temp;
          }
       }
    } 
    // print the final rankings for the players
    printf("Game Results:\n");
    for (int i = 0; i < num_players; i++){
        printf("Name:%s Final Score: %d\n", players[i].name, players[i].score);
    }
}

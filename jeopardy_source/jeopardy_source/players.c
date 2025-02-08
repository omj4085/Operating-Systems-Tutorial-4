/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
//this for loop will go through the list of the 4 players
    for(int i = 0; 1<num_players; i++){
//strcmp is to compare the players name with a given name and return an int for which string is bigger
        if (strcmp(players [i].name, name) ==0){
//if the players name matches with an existing one then it returns true
            return true;
        }
    }
//returns false if the player doesnt exist
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{
//loops through the list of players
    for(int i=0; i<num_players; i++){
//cimpares player name with given anem
        if(strcmp(players[i].name, name)==o){
//updates the players score
            players[i].score += score;
//leaves loop once the player is found
            break;
        }
    }
}

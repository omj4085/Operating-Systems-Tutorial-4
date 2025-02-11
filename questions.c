/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * Paris Scasserra ID:100815670
 * Om Jariwala ID:100863065
 * Best Akinlabi ID:100837728
 * Riya Rajesh ID: 100869701

 * All rights reserved.
 *
 */

//Sites used for gathering questions:
//https://www.instacart.com/company/ideas/fun-food-trivia-questions/
//https://animalmedical.org/fun-facts
//https://www.watercoolertrivia.com/trivia-questions/computer-trivia-questions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

//Define the categories and questions
char categories[NUM_CATEGORIES][MAX_LEN] = {
	"Computers",
	"Animals",
	"Food"
};
question questions[NUM_QUESTIONS]; 
// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    //Each 3 rows in the array is of the question format: computer,\nanimal,\nfood
    char questions_text[NUM_QUESTIONS][MAX_LEN] = {
        "What is the first piece of software implemented by Microsoft to relax users?",
        "What mammal is capable of flight?",
        "What food does not expire?",

        "What preceeded ethernet as the first public example of a packet-based network service?",
        "Which animal has 4 noses?",
        "Where were french fries created?",

        "What brand was formed from a computer engineer at Atari?",
        "What animal can swim fast and is a carnivore, but can't stick its tongue out?",
        "What food is illegal to sell passed 6pm without a doctor's note?",

        "What was the name of the wide-spread virus attacking Windows devices in 2017?",
        "What kind of mosqutioes bite?",
        "Where were Doritos invented?"
    };

    //Each row in the array is of the question format: computer, animal, food
    char answers_text[NUM_QUESTIONS][MAX_LEN] = {
        "Solitaire", "Bat", "Honey",

        "ALOHAnet", "Slug", "Belgium",
        
        "Apple", "Crocodile", "Icecream",

        "WannaCry", "Females", "Disneyland"
    };

    int category_current;
    int value_current;

    int values[] = {100, 200, 300, 400}; //Gets looped over every category

    for(int i=0; i<NUM_QUESTIONS; i++) {
        category_current = i / 4;  //Since every category has 4 possible questions and answers divide by 4
        value_current = i % 4; //Loops through values

        strcpy(questions[i].category, categories[category_current]);
        strcpy(questions[i].question, questions_text[i]);
        strcpy(questions[i].answer, answers_text[i]);

        questions[i].value = values[value_current];
        questions[i].answered = false;
    }
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("Here are the available categories:\n");
    for(int i=0; i<NUM_CATEGORIES; i++) {
        printf("Category: %s\n", categories[i]);
        for(int j=0; j<NUM_QUESTIONS; j++) {
            if(strcmp(questions[j].category, categories[i]) == 0 && !questions[j].answered) {
                printf(" .*. $%d\n", questions[j].value);
            }
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i=0; i<NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category)==0 && !questions[i].answered && questions[i].value==value) {
            printf(" .*.*. Question: %s\n", questions[i].question);
            return;
        }
    }

    printf(" .*.*. Questions not found.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    //bool answer_final = false;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            //answer_final = strcmp(questions[i].answer, answer) == 0;
            return strcmp(questions[i].answer, answer) ==0;
        }
    }

    //In any other case program will return false for answer.
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    //bool answer_final = false;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            //answer_final = questions[i].answered;
            return questions[i].answered;
        }
    }

    //Same as previous function, in any other case program will return false for answer.
    return false;
}

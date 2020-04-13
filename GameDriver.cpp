// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Game Driver

#include <iostream> 
#include "Object.h"
#include "Player.h"
#include "Game.h"
using namespace std; 

int main(){
    //Var
    int user_input;
    int secondary_input;
    int secondary_input2;
    string answerTrivia;
    int answerMath;
    int index;
    string answerRiddle;
    string playerNameInput;
    
    Game game;
    
    cout << endl;
    cout << "Welcome to Planet Expedition" << endl;
    cout << endl;
    cout << "Earth is being destroyed! You have been sent out to find a series of mysterious objects that will save the planet." << endl;
    cout << endl;
    cout << "You must collect the most valuable object at each planet to reach the final planet, Titan." << endl;
    cout << endl;
    cout << "In order to find these objects, you must increase strength, intelligence, and money along the way. " << endl;
    cout << endl;
    cout << "Your path is as follows: Earth --> Pax ---> Xena ---> Titan"<< endl;
    cout << endl;
    cout << "You begin on Earth." << endl;
    cout << endl;
    cout << endl;
    
    //Enter first player
    cout << "Enter your player name: " << endl;
    cin >> playerNameInput;
    
    game.addCharacter(playerNameInput);
    game.setCharacter(playerNameInput);
    game.setTests();
    
    while(user_input != 6){
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Move to next planet" << endl;
        cout << "2. Build Intelligence" << endl;
        cout << "3. Build Strength" << endl;
        cout << "4. Gamble" << endl;
        cout << "5. Find Objects" << endl;
        cout << "6. Quit" << endl;
        cout << "----Player Stats----" << endl;
        //PRINT STATS (intelligence, strength, money, characterScore, planet on)
        game.printStats(game.getCurrentPlayer());

        cin >> user_input;
        if(user_input < 1 || user_input > 8){
            cout << "Invalid option." << endl;
            user_input = 0;
        }
        
        
        switch(user_input){
            case 1: 
                    //If you can move to next planet (object obtained)
                    if(game.getPlanet() == "Earth" && game.getNumObtainedObjects() == 1){
                        //you obtained the first object, set new planet
                        game.setPlanet("Pax");
                        cout << "You are moving to planet Pax" << endl;
                    } else if (game.getPlanet() == "Pax" && game.getNumObtainedObjects() == 2){
                        //you obtained the second object, set new planet
                        game.setPlanet("Xena");
                        cout << "You are moving to planet Xena" << endl;
                    } else if (game.getPlanet() == "Xena" && game.getNumObtainedObjects() == 3){
                        //you obtained the third object, set new planet
                        game.setPlanet("Titan");
                        cout << "CONGRATS! You made the move to the final planet, Titan. Your efforts greatly helped to save Earth!" << endl;
                        user_input = 6;
                    } else {
                        cout << "You cannot move on to the next planet. You must find the object list first. Gain intelligence, strength, or money to find objects." << endl;
                    }

                    break;
            
            case 2: 
                    //Second Menu
                    cout << "Select a numerical option:" << endl;
                    cout << "======Secondary Menu=====" << endl;
                    cout << "1. Trivia" << endl;
                    cout << "2. Math" << endl;
                    cout << "3. Riddle" << endl;
                    
                    cin >> secondary_input;
                    
                    if(secondary_input == 1){
                        cout << "Answer the following trivia question with 'T' for True or 'F' for false" << endl;
                        index = game.getTriviaQuestion();
                        cin >> answerTrivia;
                        
                        //if player gets trivia question correct, reward with intelligence points
                        if(game.getTriviaAnswer(index) == answerTrivia){
                            cout << "Correct! Added intelligence." << endl;
                            game.addIntelligence(3);
                        }
                        
                    } else if(secondary_input == 2) {
                        cout << "Answer the following trivia question with an integer value" << endl;
                        index = game.getMathQuestion();
                        cin >> answerMath;
                        //if player gets math question correct, reward with intelligence points
                        if(game.getMathAnswer(index) == answerMath){
                            cout << "Correct! Added intelligence." << endl;
                            game.addIntelligence(3);
                        }
                    } else if (secondary_input == 3) {
                        cout << "Answer the following trivia question with a single word answer" << endl;
                        index = game.getRiddleQuestion();
                        cin >> answerRiddle;
                        //if player gets riddle question correct, reward with intelligence points
                        if(game.getRiddleAnswer(index) == answerRiddle){
                            cout << "Correct! Added intelligence." << endl;
                            game.addIntelligence(3);
                        }
                    } else {
                        cout << "Invalid option." << endl;
                    }
                    
                    break;
            case 3: 
                    //Second Menu
                    cout << "Select a numerical option:" << endl;
                    cout << "======Secondary Menu=====" << endl;
                    cout << "1. Brawl" << endl;
                    cout << "2. Help villagers" << endl;
                    
                    cin >> secondary_input2;
                    
                    if(secondary_input2 == 1){
                        //find another player to fight
                        //Use probability (EX: 60% chance certain event will occur) to determine winner based off of strength
                        //award strength points if win
                    } else if(secondary_input2 == 2) {
                        //give player a task to complete that helps villagers (maybe just print a RANDOM task from a list of tasks possible (select a random value in range 1-6))
                        //award strength points for task
                    } else {
                        cout << "Invalid option." << endl;
                    }
                    
                    
                    break;
                    
            case 4: 
                    //Gamble 
                    //print how much money player currently has
                    cout << "How much money would you like to gamble? " << endl;
                    //do some random calcualtion???
                    //print how much money was won or lost
                    //print new money calculation
                    
                    break;
            case 5: 
                    //Check to see if characterScore is high enough for the planet (Planet 1 = ___, Planet 2 = ___, Planet 3 = ___)
                        //If so, read list of Objects (if statements...)
                            //Based on characterScore, they can only choose a certain object
                            //Write certain object to object file
                        //If not, tell use what they need to add to their score to get the list
                    
                    break;
            case 6: 
                    break;
        }
        
    }
    cout << "Good bye!" << endl;
    
    return 0;
    
}

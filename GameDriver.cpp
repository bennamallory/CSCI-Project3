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
    string playerNameInput;
    
    Game game;
    
    cout << "Welcome to Planet Expedition" << endl;
    cout << "Earth is being destroyed! You have been sent out to find a series of mysterious objects that will save the planet." << endl;
    cout << "Your path is as follows: Earth --> _____ ---> _____ ---> Final Planet"<< endl;
    
    //Enter first player
    cout << "Enter your first player name: " << endl;
    cin >> getline(playerNameInput);
    
    game.addCharacter(playerNameInput);
    game.setCharacter(playerNameInput);
    
    while(user_input != 6){
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Move to next planet" << endl;
        cout << "2. Build Intelligence" << endl;
        cout << "3. Build Strength" << endl;
        cout << "4. Gamble" << endl;
        cout << "5. Find Objects" << endl;
        cout << "6. Quit" << endl;
        
        //PRINT STATS (intelligence, strength, money, characterScore, planet on)
        game.printStats(game.getCurrentPlayer());

        cin >> user_input;
        if(user_input < 1 || user_input > 8){
            cout << "Invalid option." << endl;
            user_input = 0;
        }
        
        
        switch(user_input){
            case 1: 
                    //If you can move to next planet, reset the objects array and set planetOn to next planet
                    //If you cannot move to next planet, display current planet, check if character score is high enough (1- , 2- , 3- )
                    //If planetOn == finalPlanet, then print some success thing and end game.. 
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
                        //give trivia question
                        //if player gets trivia question correct, reward with intelligence points
                    } else if(secondary_input == 2) {
                        //give math question
                        //if player gets math question correct, reward with intelligence points
                    } else if (secondary_input == 3) {
                        //give riddle
                        //if player gets riddle question correct, reward with intelligence points
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

// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Game Driver

#include <iostream> 
#include "Object.h"
#include "Player.h"
#include "Game.h"
using namespace std; 

int randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

int main(){
    //Var
    int user_input;
    int secondary_input;
    int secondary_input2;
    string answerTrivia;
    int answerMath;
    int index;
    int totalObjVal;
    string answerRiddle;
    string playerNameInput;
    int fighterChoice=1;
    
    //Game questions
    string triviaQ[10] = {"Elliptical galaxies are the most common type of galaxies in the universe (T/F)", "The hottest place in the universe is the Boomerang Nebula (T/F)", "The Universe is 13.8 billion years old (T/F)", "30 percent of the universe is dark matter (T/F)", "There are 8 planets in Earth's solar system (T/F)", "The largest planet in Earth's solar system is Mercury (T/F)", "A black hole has such a strong gravitational pull that even light cannot escape it (T/F)", "Proxima Centauri is the closest star to the sun (T/F)","The largest type of star in the universe is the protostar (T/F)","The white dwarf is the most common type of star in the universe (T/F)" };
    string triviaA[10] = {"T","F","T","F", "T","F", "T", "T", "F", "F"};
    string mathQ[10] = {"What is 5 + 5254 ?", "What is 2*10 ?", "What is 2 * 2 * 2 ?", "What is 10 squared?", "What is 50 / 2 ?", "What is 14-5*3", "What is 5*6/3-1 ?", "What is the square root of 9 multiplied by 2?", "What is the smallest factor of 12?", "What is 15 % 3 ?" };
    int mathA[10] = {5259, 20, 8, 100, 25, -1, 9, 6, 2, 0};
    string riddleQ[10] = {"What 4-letter word can be written forward, backward or upside down, and can still be read from left to right?", "What kind of goose fights with snakes?" , "I am wet when drying. What am I?", "You answer me, although I never ask you questions.", "What word is always pronounced wrong?", "The leaves are on the fruit, The fruits is on the leaves.", "The one who has it does not keep it. It is large and small. It is any shape.", "What has an eye but can not see?","What color is the wind?", "If you drop a yellow hat in the Red Sea, what does it become?"};
    string riddleA[10] = {"noon", "mongoose","towel","phone", "wrong", "pineapple","gift","needle","blew", "wet"};
    
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
    //game.setTests();
    
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
                        srand(time(0));
                        index = randomNumbers(0,9);
                        cout << triviaQ[index] << endl;
                        cin >> answerTrivia;
                        
                        //if player gets trivia question correct, reward with intelligence points
                        if(triviaA[index] == answerTrivia){
                            cout << "Correct! Added intelligence." << endl;
                            game.addIntelligence(3);
                            cout << endl;
                        } else {
                            cout << "INCORRECT. No points awarded." << endl;
                            cout << endl;
                        }
                        
                    } else if(secondary_input == 2) {
                        cout << "Answer the following trivia question with an integer value" << endl;
                        srand(time(0));
                        index = randomNumbers(0,9);
                        cout << mathQ[index] << endl;
                        cin >> answerMath;
                        //if player gets math question correct, reward with intelligence points
                        if(mathA[index] == answerMath){
                            cout << "Correct! Added intelligence." << endl;
                            game.addIntelligence(3);
                            cout << endl;
                        } else {
                            cout << "INCORRECT. No points awarded." << endl;
                            cout << endl;
                        }
                    } else if (secondary_input == 3) {
                        cout << "Answer the following trivia question with a single word answer" << endl;
                        srand(time(0));
                        index = randomNumbers(0,9);
                        cout << riddleQ[index] << endl;
                        cin >> answerRiddle;
                        //if player gets riddle question correct, reward with intelligence points
                        if(riddleA[index] == answerRiddle){
                            cout << "Correct! Added intelligence." << endl;
                            game.addIntelligence(3);
                            cout << endl;
                        } else {
                            cout << "INCORRECT. No points awarded." << endl;
                            cout << endl;
                        }
                    } else {
                        cout << "Invalid option." << endl;
                        cout << endl;
                    }
                    
                    break;
             case 3: 
                    //Second Menu
                    cout << "Select a numerical option:" << endl;
                    cout << "======Secondary Menu=====" << endl;
                    cout << "1. Brawl" << endl;
                    cout << "2. Help villagers" << endl; //since this is easier, maybe allow this to occur only a certain number of times?
                    
                    cin >> secondary_input2;
                    
                    if(secondary_input2 == 1){
                        //find another player to fight
        //i have no clue how to change the character we want
                        game.readFighters("fighters.txt"); 
                        //Use probability (EX: 60% chance certain event will occur) to determine winner based off of strength
                        if (game.fightTime(fighterChoice)==true){
                            cout<<"It looks like you're stronger than your opponent! You win this fight! And it looks like you've made a new friend that wants to join you!"<<endl;
                            cout<<"They're now a part of your clan!"<<endl;
                            game.addStrength(3); //award more strength points if win
        //how to do this    game.addCharacter(fighters[fighterChoice].getName()); //adds fighter to your player array
                        }
                        else{
                            cout<<"OOF it doesn't seem like you could win but since you tried, you've become a little bit stronger!";
                            game.addStrength(1); //awards less strength from trying
                        }
                        fighterChoice++;
                    } else if(secondary_input2 == 2) {
                        //give player a task to complete that helps villagers (maybe just print a RANDOM task from a list of tasks possible (select a random value in range 1-6))
                        //award strength points for task
                        cout<<"Option 2 isn't running yet!"<<endl;
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
                    if(game.getCharStat(game.getCurrentPlayer()) >= 10 && game.getPlanet() == "Earth"){
                        cout << "Reading objects..." << endl;
                        //read list of objects
                        game.readObjects("earthObjects.txt");
                        
                        //add highest score object to file
                        totalObjVal = game.writeObject("collectedObjects.txt");
                        cout << "You now have a list value of: " << totalObjVal << endl;
                        
                    } else if (game.getCharStat(game.getCurrentPlayer()) >= 20 && game.getPlanet() == "Pax" ){
                        //read list
                        cout << "Reading objects..." << endl;
                        game.readObjects("paxObjects.txt");
                        
                        //add highest score object to file
                        totalObjVal = game.writeObject("collectedObjects.txt");
                        cout << "You now have a list value of: " << totalObjVal << endl;
                        
                    } else if (game.getCharStat(game.getCurrentPlayer()) >= 30 && game.getPlanet() == "Zena") {
                        //read list of objects
                        cout << "Reading objects..." << endl;
                        game.readObjects("zenaObjects.txt");
                        
                        //add highest score object to file
                        totalObjVal = game.writeObject("collectedObjects.txt");
                        cout << "You now have a list value of: " << totalObjVal << endl;
                    } else {
                        cout << "You do not have a high enough character score to find objects. Try increasing strength, intelligence, or money." << endl;
                    }
                    
                    break;
            case 6: 
                    break;
        }
        
    }
    cout << "Good bye!" << endl;
    
    return 0;
    
}

// CS1300 Spring 2020
// Author: Mallory Benna and Sravya Dhanwada
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
    int fighterChoice=0;
    double moneyGambled;
    int randomPercent;
    int randomSituationCounter=1;
    int randomSituationIndex;
    int situationResponse;
    bool chosen1 = false;
    bool chosen2 = false;
    bool chosen3 = false;
    string randomSituation;
    
    //Game questions
    string triviaQ[10] = {"Elliptical galaxies are the most common type of galaxies in the universe (T/F)", "The hottest place in the universe is the Boomerang Nebula (T/F)", "The Universe is 13.8 billion years old (T/F)", "30 percent of the universe is dark matter (T/F)", "There are 8 planets in Earth's solar system (T/F)", "The largest planet in Earth's solar system is Mercury (T/F)", "A black hole has such a strong gravitational pull that even light cannot escape it (T/F)", "Proxima Centauri is the closest star to the sun (T/F)","The largest type of star in the universe is the protostar (T/F)","The white dwarf is the most common type of star in the universe (T/F)" };
    string triviaA[10] = {"T","F","T","F", "T","F", "T", "T", "F", "F"};
    string mathQ[10] = {"What is 5 + 5254 ?", "What is 2*10 ?", "What is 2 * 2 * 2 ?", "What is 10 squared?", "What is 50 / 2 ?", "What is 14-5*3", "What is 5*6/3-1 ?", "What is the square root of 9 multiplied by 2?", "What is the smallest factor of 12?", "What is 15 % 3 ?" };
    int mathA[10] = {5259, 20, 8, 100, 25, -1, 9, 6, 2, 0};
    string riddleQ[10] = {"What 4-letter word can be written forward, backward or upside down, and can still be read from left to right?", "What kind of goose fights with snakes?" , "I am wet when drying. What am I?", "You answer me, although I never ask you questions.", "What word is always pronounced wrong?", "The leaves are on the fruit, The fruits is on the leaves.", "The one who has it does not keep it. It is large and small. It is any shape.", "What has an eye but can not see?","What color is the wind?", "If you drop a yellow hat in the Red Sea, what does it become?"};
    string riddleA[10] = {"noon", "mongoose","towel","phone", "wrong", "pineapple","gift","needle","blew", "wet"};
    string task[10]={"Find some metal to build the the spaceship","Find a extraterrestrial plant to help heal the people", "Help the young boy find his mother", "Kill the greedy ferodaunt creatures that terrorize the villagers", "Battle the bandits stealing weapons and food from the factory", "Fix the old factory", "Repair the bridge that crosses from the old land to the new land", "Guard the gate to the Nukara town from rabidopterus for a day", "Protect the ancient forest from wood hunters", "Perfect a handstand"};
    string situations[10]={"You found 5 spacecoins!", "You found 10 spacecoins!", "You found 20 spacecoins!", "An asteroid is coming towards your planet!", "A lost child comes crying to you and asks you for help to find their parents.","You've found some expensive silk robes!","You just found a sun shooter 340! A powerful weapon to defeat powerful enemies!", "You found a notebook with ancient remedies for wounds!","Someone is trying to loot you!", "A ravenous rabidopterus comes and attacks you!"};
    string responses[10]={"1.Take it for yourself and buy an engineering manual for your ship\n2.Take it for yourself and save it\n3.Give it to someone who needs it more", "1. Take it for yourself and buy an engineering manual for your ship\n2. Take it for yourself and save it\n3. Give it to someone who needs it more", "1. Take it for yourself and buy an engineering manual for your ship\n2. Take it for yourself and save it\n3. Give it to someone who needs it more","1. Activate the neutrino defense shield and pray for the best\n2. Gather all the fighters to shoot plasma rays at the asteroid and break it up!\n3. Evacuate as many as you can onto your ship, only a quarter of the town fits!", "1. Hack the ministry's security portal to find the parents' whereabouts\n2. Carry the child on your shoulders to help find their parents\n3. Steal the kid's money", "1. Apply a disappearing spell on them and disguise yourself in dangerous territory\n2. Take them!\n3. Give it to someone who needs it more", "1. Take it to help you in your journey!\n2. Sell it and make some money!" , "1. Take it and and help a friend in need! \n2. Sell it in the black market for money","1. Avoid conflict to maintain peace and let them have your belongings\n2. Fight them off and kill them if you have to!","1. Run away and trick them into following a dead trail.\n2. Fight them off like a true warrior!"};

    Game game;
    
    cout << endl;
    cout << "Welcome to Planet Expedition" << endl;
    cout << endl;
    cout << "Earth is being destroyed! You have been sent out to find a series of mysterious objects that will save the planet." << endl;
    cout << endl;
    cout << "You must collect the most valuable object at each planet to reach the final planet, Titan." << endl;
    cout << endl;
    cout << "In order to find these objects, you must increase strength, intelligence, and money along the way.\n\nYou can even make friends and build your friendships by doing nice things along the way!\n\nSometimes they appear in the most unexpected of places so always try to seek them out ;)" << endl;
    cout << endl;
    cout<< "The first checkpoint is to get a total score of 10, then you can find the first object and move to the next planet."<<endl;
    cout<<endl;
    cout<< "You can find more objects once you reach a score of 15 and then 20." <<endl;
    cout<<endl;
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
    game.readFighters("fighters.txt"); 

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
        
        if (randomSituationCounter%4!=0){ //if the random situation does not occur then carry out with normal personality building tasks
            switch(user_input){
                case 1: 
                        //If you can move to next planet (object obtained)
                        if(game.getPlanet() == "Earth" && game.getNumObtainedObjects() >= 1){
                            //you obtained the first object, set new planet
                            game.setPlanet("Pax");
                            cout << "You are moving to planet Pax" << endl;
                        } else if (game.getPlanet() == "Pax" && game.getNumObtainedObjects() >= 2){
                            //you obtained the second object, set new planet
                            game.setPlanet("Xena");
                            cout << "You are moving to planet Xena" << endl;
                        } else if (game.getPlanet() == "Xena" && game.getNumObtainedObjects() >= 3){
                            //you obtained the third object, set new planet
                            game.setPlanet("Titan");
                            cout << "CONGRATS! You made the move to the final planet, Titan. Your efforts greatly helped to save Earth!" << endl;
                            game.endStats();
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
                                cout<< "Since riddles are hard, Master Wizona finds you a worthy friend for solving it."<<endl;
                                game.addFriendship(4);
                                cout<<"Friendships made!"<<endl;
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
                            //Use probability (EX: 60% chance certain event will occur) to determine winner based off of strength
                            if (fighterChoice>=5){
                                cout<<"Sorry no more fighters left, choose another task!"<<endl;
                            }else{
                                if (game.fightTime(fighterChoice)==true){
                                    cout<<"It looks like you're stronger than your opponent! You win this fight! And it looks like you've made a new friend that wants to join you!"<<endl;
                                    cout<<"They're now a part of your clan!"<<endl;
                                    game.addStrength(3); //award more strength points if win
                                    cout<<"Strength added!"<<endl;
                                    game.addCharacter(game.returnName(fighterChoice)); //adds fighter to your player array 
                                    fighterChoice++;
                                    game.addFriendship(5);
                                    cout<<"Friendships made!"<<endl;
                                } else{
                                    cout<<"OOF it doesn't seem like you could win but since you tried, you've become a little bit stronger!"<<endl;
                                    game.addStrength(1); //awards less strength from trying
                                    cout<<"Strength added!"<<endl;
                                }
                            }
                        } else if(secondary_input2 == 2) {
                                cout<<"It looks like you have kind heart!"<<endl;
                                //give player a task to complete that helps villagers (maybe just print a RANDOM task from a list of tasks possible (select a random value in range 1-6))
                                srand(time(0));
                                index = randomNumbers(0,9);
                                cout <<"Task: "<< task[index] << endl;
                                //award strength points for task
                                game.addStrength(4);
                                cout<<"Strength added!"<<endl;
                                game.addFriendship(4);
                                cout<<"Friendships made!"<<endl;
                            } else {
                                cout << "Invalid option." << endl;
                            }
                        break;
                        
                case 4: 
                        //Gamble 
                        //print how much money MAIN player currently has
                        game.printMoney(playerNameInput); 
                        cout << "How much money would you like to gamble? " << endl;
                        cin>> moneyGambled;
                        //do some random calcualtion???
                        srand(time(0));
                        randomPercent=randomNumbers(-40,160);
                        cout<<game.gambleTime(moneyGambled, randomPercent, playerNameInput)<<endl;
                        break;
                case 5: 
                        
                        //Check to see if characterScore is high enough for the planet (Planet 1 = ___, Planet 2 = ___, Planet 3 = ___)
                        if(game.getCharStat(game.getCurrentPlayer()) >= 10 && game.getPlanet() == "Earth"){
                            if(chosen1){
                                cout << "You have already obtained the objects from this planet. Try moving to the next." << endl;
                            } else {
                                cout << "Reading objects..." << endl;
                                //read list of objects
                                game.readObjects("earthObjects.txt");
                                cout << "This object is required to restore communications on Earth.\nBlessed with the power of past generations, it will allow you to reconnect with rest of humankind."<<endl;
                                //add highest score object to file
                                totalObjVal = game.writeObject("collectedObjects.txt");
                                cout << "You now have a list value of: " << totalObjVal << endl;
                                chosen1 = true;
                            }
                            
                            
                        } else if (game.getCharStat(game.getCurrentPlayer()) >= 15 && game.getPlanet() == "Pax" ){
                            if(chosen2){
                                 cout << "You have already obtained the objects from this planet. Try moving to the next." << endl;
                            } else {
                                //read list
                                cout << "Reading objects..." << endl;
                                game.readObjects("paxObjects.txt");
                                
                                //add highest score object to file
                                totalObjVal = game.writeObject("collectedObjects.txt");
                                cout << "You now have a list value of: " << totalObjVal << endl;
                                cout << "This object is a historic remnant of old Earth. If you dig deep miles into the soil, you will find Dust.\nCivilization had built and built till Dust was buried deep below and all the creatures that needed it died as well.\nUse this wisely and rebuild a better Earth." <<endl;
                                chosen2 = true;
                            }
                            
                            
                        } else if (game.getCharStat(game.getCurrentPlayer()) >= 20 && game.getPlanet() == "Xena") {
                            if(chosen3){
                                cout << "You have already obtained the objects from this planet. Try moving to the next." << endl;
                            } else {
                                 //read list of objects
                                cout << "Reading objects..." << endl;
                                game.readObjects("zenaObjects.txt");
                                
                                //add highest score object to file
                                totalObjVal = game.writeObject("collectedObjects.txt");
                                cout << "You now have a list value of: " << totalObjVal << endl;
                                cout << "This object is magic and truth. It speaks boldly and reminds you that Earth is small, and you are as well.\nKeep it happy and the Galaxy will favor you." <<endl;
                                chosen3 = true;
                            }
                            
                        } else {
                            cout << "You do not have a high enough character score to find objects. Try increasing strength, intelligence, or money." << endl;
                        }
                        
                        break;
                case 6: 
                        break;
            } //to incorporate some random events
        }else if (randomSituationCounter%4==0){                      //every 3 times you choose a menu option, then something unexpected will happen
            cout<<"Something unexpected is happening!"<<endl;
            srand(time(0));
            randomSituationIndex=randomNumbers(0,9);
            randomSituation=situations[randomSituationIndex];   //a situation is chosen from an array of situations
            cout<<randomSituation<<endl;
            cout<<responses[randomSituationIndex]<<"\n"<<endl;  //options to respond are given
            cout<<"Choose the number on the list"<<endl;        //the user can respond to the situation by choosing an option
            cin>>situationResponse;
            for (int i=0;i<6;i++){                              //the first 6 situations have 3 options each, must make sure that the user doesn't type other options
                if (randomSituation==situations[i]){
                    if (situationResponse<4 && situationResponse>0){
                        if (randomSituation==situations[0]||randomSituation==situations[1]||randomSituation==situations[2]){ //the first 3 situations have the same options
                            if (situationResponse==1){
                                game.addIntelligence(4);
                                cout<<"Intelligence added!"<<endl;
                            } else if (situationResponse==2){
                                game.addStrength(4);
                                cout<<"Strength added!"<<endl;
                            }else if (situationResponse==3){
                                game.addMoney(4);
                                cout<<"Money added!"<<endl;
                            }
                        }else if (randomSituation==situations[3]){ //if the situation is the 4th one
                            if (situationResponse==1){
                                game.addIntelligence(4);
                                cout<<"Intelligence added!"<<endl;
                            }else if (situationResponse==2){
                                game.addStrength(4);
                                cout<<"Strength added!"<<endl;
                            }else if (situationResponse==3){
                                game.addFriendship(4);
                                cout<<"Friendships made!"<<endl;
                            }
                        }else if (randomSituation==situations[4]){
                            if (situationResponse==1){
                                game.addIntelligence(4);
                                cout<<"Intelligence added!"<<endl;
                                game.addFriendship(4);
                                cout<<"Friendships made!"<<endl;
                            }else if (situationResponse==2){
                                game.addStrength(4);
                                cout<<"Strength added!"<<endl;
                                game.addFriendship(4);
                                cout<<"Friendships made!"<<endl;
                            }else if (situationResponse==3){
                                game.addMoney(6);
                                cout<<"Money added!"<<endl;
                            }
                        }else if (randomSituation==situations[5]){
                            if (situationResponse==1){
                                game.addIntelligence(4);
                                cout<<"Intelligence added!"<<endl;

                            }else if (situationResponse==2){
                                game.addMoney(4);
                                cout<<"Money added!"<<endl;
                            }else if (situationResponse==3){
                                game.addFriendship(6);
                                cout<<"Friendships made!"<<endl;
                            }
                        }
                        
                    }else{
                        cout<<"Invalid option! Pay more attention to instructions! You couldn't react in time and the opportunity to gain skills passed you by. Sux man"<<endl;
                    }
                }
            }
            for (int i=6;i<10;i++){
                if (randomSituation==situations[i]){ //if the question is one of the last 4 in the situations array
                    if (situationResponse==1 || situationResponse==2){ //only 2 options for the last 4 questions
                        if (randomSituation==situations[6]){
                            if(situationResponse==1){
                                game.addStrength(4);
                                cout<<"Strength added!"<<endl;
                            }else if (situationResponse==2){
                                game.addMoney(4);
                                cout<<"Money added!"<<endl;
                            }
                            
                        }else if (randomSituation==situations[7]){
                            if(situationResponse==1){
                                game.addIntelligence(4);
                                cout<<"Intelligence added!"<<endl;
                            }else if (situationResponse==2){
                                game.addMoney(4);
                                cout<<"Money added!"<<endl;
                            }
                        }else if (randomSituation==situations[8]||randomSituation==situations[9]){ //8 and 9 have the same changes Intelligence and Strength depending on if option 1 or 2 was chosen 
                            if(situationResponse==1){
                                game.addIntelligence(4);
                                cout<<"Intelligence added!"<<endl;
                            }else if (situationResponse==2){
                                game.addStrength(4);
                                cout<<"Strength added!"<<endl;
                            }
                        }
                            
                    }else{
                            cout<<"Invalid option! Pay more attention to instructions! You couldn't react in time and the opportunity to gain skills passed you by. Sux man"<<endl;
                    }
                }
            }
        }
        randomSituationCounter++;
    }
            
    
    cout << "Good bye!" << endl;
    
    return 0;
    
}

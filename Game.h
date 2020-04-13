// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Game Header File

#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "Player.h"

#include <iostream> 
using namespace std; 

class Game{
    public:
        Game(); //Default constructor
        //Getters
        int getNumPlayers(); //get the number of players
        int getNumObjects(); //get the number of objects
        string getCurrentPlayer(); //get the current player
        int readObjects(string filename); //read a file of objects and their values, return number of objects
        int writeObject(string filename); //write object(s) to a new file, return sum of all their values
        string getPlanet(); //get the current planet name
        //string getTriviaQuestion --- choose random value from array, print the question, return the answer
        //string getMathQuestion -- ""
        //string getRiddleQuestion -- ""
    
        //Setters
        void setPlanet(string planetOn_); //set the current planet player is on
        void printObject(string objectName_); //print designated object and its score
        void printStats(string playerName_); //print intelligence, strength, money, and characterScore
        void setCharacter(string playerName); //set current character you are using for activities
        void addCharacter(string playerName); //add a character to the clan

        

    private: 
        Player players[50];
        Object objects[100];
        int numPlayers;
        int numObjects;
        string planetOn;
        string currentCharacter;
        int split(string splitPhrase, char separator, string afterSplit[], int size); //split function to read files
        //trivia array
        //trivia array answers
        //math array
        //math array answers
        //riddle array 
        //riddle array answers
        // help villagers array choices

}; 

#endif

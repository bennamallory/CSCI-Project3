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
        int readObjects(string filename); //read a file of objects and their values, return number of objects
        int writeObjects(string filename); //write object(s) to a new file, return sum of all their values
        string getPlanet(); //get the current planet name
    
        //Setters
        void setPlanet(string planetOn_); //set the current planet player is on
        void printObject(Object object_); //print designated object and its score
        void printStats(Player player); //print intelligence, strength, money, and characterScore
        void setCharacter(string playerName); //set current character you are using for activities
        void addCharacter(string playerName); //add a character to the clan
        

    private: 
        Player players[50];
        Object objects[100];
        int numPlayers;
        int numObjects;
        string planetOn;
        string currentCharacter;
        

}; 

#endif

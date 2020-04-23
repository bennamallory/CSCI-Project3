// CS1300 Spring 2020
// Author: Mallory Benna and Sravya Dhanwada
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
        double getCharStat(string playerName_); //return the characterScore for a player
        int getNumObtainedObjects(); //return the number of objects in your obtained objects list
        int readFighters(string filename);
        bool fightTime(int fighterIndex);
        double gambleTime(double moneyGambled, int randomPercent, string playerName_); //computes how much money won in gambling
        string returnName(int fighterIndex);
    
        //Setters
        void setPlanet(string planetOn_); //set the current planet player is on
        void printObject(string objectName_); //print designated object and its score
        void printStats(string playerName_); //print intelligence, strength, money, and characterScore
        void setCharacter(string playerName); //set current character you are using for activities
        void addIntelligence(int val); //add val to player intelligence
        void addStrength(int val); //add val to player strength
        void addMoney(double val); //add val to player money
        void addFriendship(int val); //add val to player friendship
        void addCharacter(string playerName); //add a character to the clan
        void setTests();
        void printMoney(string playerName_); //prints out money of main character
        void endStats();
        

    private: 
        Player players[50];
        Player fighters[15];
        Object objects[100];
        Object objectsCollected[100];
        int numPlayers;
        int numObjects;
        int numObtainedObj;
        string planetOn;
        string currentCharacter;
        int numFighters;
        int split(string splitPhrase, char separator, string afterSplit[], int size); //split function to read files

}; 

#endif

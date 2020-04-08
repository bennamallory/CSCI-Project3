// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Object Class Source File

#include <iostream> 
#include "Object.h"
#include "Player.h"
#include "Game.h"
using namespace std; 

//Default constructor
Game::Game(){
    numPlayers = 0;
    numObjects = 0;
    planetOn = "";
}


int Game::getNumPlayers(){
    return numPlayers;
}

int Game::getNumObjects(){
    return numObjects;
}

int Game::readObjects(string filename){
    //read a file of objects
    //store the objects in the objects array (REPLACE ALL VALUES IN THIS ARRAY FOR EACH NEW PLANET)
    //return the number of objects in the array
    return numObjects;
}

int Game::writeObjects(string filename){
    //look in objects array
    //find the object that has the highest value score -- that is the object you are adding to the file
    if(numObjects == 0){
        cout << "There are no objects in the objects array." << endl;
        totalValues = 0;
    } else {
        //int highest = getObjectValue();
        for(int i=0; i < numObjects; i++){
            
        }
        
        
        //open "filename" to write to
        //write the object to the end of the file
        
        //read the same file
        //calculate the total value of all objects in the list
        //return the total value of all objects in the list
        
    }
    
    
    
    
    return totalValues;
}

string Game::getPlanet(){
    return planetOn;
}

void Game::setPlanet(string planetOn_){
    planetOn = planetOn_;
}

void Game::printObject(Object object_){
    //find object in objects array
    //print object name
    //print object score
}

void Game::printStats(Player player_){
    //find player in players array
    //print intelligence, strength, money, and characterScore
}

void Game::setCharacter(string playerName){
    //set character you want to use to perform tasks from character array
    if(findUser(playerName, numPlayers, players)){
        currentCharacter = playerName;
    } else {
        cout << "That player is not part of the clan " << endl;
    }
}


/*
* This function checks to see if a user exists in the array
* Parameters: string user, int numPlayers_, Player playersArr[]
* Return: true or false
*/
bool findUser(string user, int numPlayers_, Player playersArr[]){
    //Find if user exists
    for(int i=0; i < numPlayers_; i++){
        if(playersArr[i].getName() == user){
            return true;
        }
    }
    
    return false;
}

void Game::addCharacter(string playerName){
    //adds character to character array at various planets
    if(numPlayers == 100){
        cout << "The players array is already full. " << playerName << " was not added." << endl;
    } else if (findUser(playerName, numPlayers, players)){
        cout << playerName << " already exists in the clan." << endl;
    } else {
        //add to library
        Player new_player;
        
        //Add username
        new_player.setUsername(playerName);
        
        //Add user to array
        players[numPlayers] = new_player;
        numPlayers++;
        
        cout << "Welcome to the clan, " << playerName << endl;
    }
}

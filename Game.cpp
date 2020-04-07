// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Object Class Source File

#include <iostream> 
#include "Object.h"
#include "Player.h"
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
    //find the object that has the _____ value score
    //open "filename" to write to
    //write the object to the end of the file
    
    //read the same file
    //calculate the total value of all objects in the list
    //return the total value of all objects in the list
    
    return /*totalValues*/;
}

string Game::getPlanet(){
    return planetOn;
}

void Game::setPlanet(planetOn_){
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

void Game::setCharacter(Player players[]){
    //set character you want to use to perform tasks from character array
}

void Game::addCharacter(Player players[]){
    //adds character to character array at various planets
}

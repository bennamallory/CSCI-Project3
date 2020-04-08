// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Player Class Source File

#include<iostream>
#include <string>
using namespace std;
#include "Player.h"

//Default constructor
Player::Player(){
    name="";
    intelligence=0;
    strength=0;
    money=0;
    characterScore=0;
}

//Parameterized constructor
void Player:: setName(string name_){
    name = name_;
}

/*
* This function gets the name of the player
* Parameters: none
* Return: string name
*/
string Player:: getName(){
    return name;
}


/*
* This function sets the intelligence of the player
* Parameters: int intelligence_
* Return: none
*/
void Player:: setIntelligence(int intelligence_){
    intelligence = intelligence_;
}


/*
* This function gets the intelligence of the player
* Parameters: none
* Return: int intelligence
*/
int Player:: getIntelligence(){
    return intelligence;
}


/*
* This function sets the money of the player
* Parameters: double money_
* Return: none
*/
void Player::setMoney(double money_){
    money = money_;
}



/*
* This function gets the money of the player
* Parameters: none
* Return: double money
*/
double Player::getMoney(){
    return money;
}


/*
* This function sets the character score of the player
* Parameters: double characterScore_
* Return: none
*/
void Player:: setCharacterScore(double characterScore_){
    characterScore = characterScore_;
}

/*
* This function gets the character score of the player
* Parameters: none
* Return: double characterScore_
*/
double Player::getCharacterScore(){
    return characterScore;
}

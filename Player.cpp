// CSC1300 Spring 2020
// Author: Mallory Benna and Sravya Dhanwada
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Player Class Source File

#include<iostream>
#include <string>
using namespace std;
#include "Player.h"

Player::Player(){
    name="";
    intelligence=5;
    strength=5;
    money=5;
    friendship=0;
    characterScore=0;
}


void Player:: setName(string name_){
    name=name_;
}


string Player:: getName(){
    return name;
}


void Player:: setIntelligence(int intelligence_){
    intelligence=intelligence_;
}


int Player:: getIntelligence(){
    return intelligence;
}


void Player::setMoney(double money_){
    money = money_;
}


double Player::getMoney(){
    return money;
}

void Player:: setStrength(int strength_){
    strength=strength_;
}

int Player::getStrength(){
    return strength;
}

double Player::calculateCharacterScore(){
    return characterScore = (strength*0.30) + (intelligence*0.40) + (money*0.20)+  (friendship*0.10);
}


double Player::getCharacterScore(){
    return characterScore; 
}

void Player::setFriendship(int friendScore){
    friendship=friendScore;
}

int Player::getFriendship(){
    return friendship;
}

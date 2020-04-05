#include<iostream>
#include <string>
using namespace std;
#include "Player.h"

Player::Player(){
    name="";
    intelligence=0;
    strength=0;
    money=0;
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
    money=money_;
}
double Player::getMoney(){
    return money;
}
void Player:: setCharacterScore(characterScore_){
    characterScore=characterScore_;
}
double Player::getCharacterScore(){
    return characterScore;
}

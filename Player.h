// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Object Player Header File

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include <string>
using namespace std;

class Player{
    private:
        string name;
        int intelligence;
        int strength;
        double money;
        double characterScore;
    public:
        Player();
        void setName(string name_); //set character name
        string getName(); //get character name
        void setIntelligence(int intelligence_); //set intelligence score
        int getIntelligence(); //get intelligence score
        void setMoney(double money_); //set money
        double getMoney(); //get amount of money 
        void setCharacterScore(double characterScore_);
        double getCharacterScore();
};
#endif

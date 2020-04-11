// CSC1300 Spring 2020
// Author: Mallory Benna and Sravya Dhanwanda
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
        //Setters
        void setName(string name_); //set character name
        void setIntelligence(int intelligence_); //set intelligence score
        void setMoney(double money_); //set money
        void setStrength(int strength_); //set strength
        void setCharacterScore(double characterScore_);
        
        //Getters
        string getName(); //get character name
        int getIntelligence(); //get intelligence score
        double getMoney(); //get amount of money 
        int getStrength(); //get strength
        double getCharacterScore();
};
#endif

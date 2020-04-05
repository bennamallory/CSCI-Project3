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
        void setCharacterScore(characterScore_);
        double getCharacterScore();
};
#endif

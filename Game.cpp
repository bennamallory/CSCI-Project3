 // CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Object Class Source File

#include <iostream> 
#include <fstream>
#include <string>
#include "Object.h"
#include "Player.h"
#include "Game.h"
using namespace std; 

//Default constructor
Game::Game(){
    numPlayers = 0;
    numObjects = 0;
    numFighters=0;
    numObtainedObj = 0;
    planetOn = "Earth";
}

/*
* This function splits a line of text
* Parameters: splitPhrase: sentence to be split, separator: comma, afterSplit[]: an empty array to store the split items, size: size of array
* Return: int count- number of items after split
*/
int Game:: split(string splitPhrase, char separator, string afterSplit[], int size){
    splitPhrase = splitPhrase + separator; 
    int count=0;
    for (int i=0;i<(int)splitPhrase.length();i++) //goes through the string
    {
        if (splitPhrase[i]==separator&& splitPhrase[i+1]==separator) //moves through the characters if delmiters occur simultaneously
        {
            i++;
        }
        if (splitPhrase[i]!=separator) //if delimiter doesnt appear, keeps taking the characters in between delimiters
        {
            afterSplit[count]=afterSplit[count]+splitPhrase[i]; 
            if (splitPhrase[i+1]==separator)//counts the word if delimiter comes after
            {
                count++;
            }
            else if (i==(int)splitPhrase.length())//counts the last word with no dilimiter after
            {
                count++;
            }
        }
    }
    if (count>size)
    {
        count=-1;
    }
    return count;
}

/*
* This function gets the number of players
* Parameters: none
* Return: int numPlayers
*/
int Game::getNumPlayers(){
    return numPlayers;
}

/*
* This function gets the number of objects
* Parameters: none
* Return: int numObjects
*/
int Game::getNumObjects(){
    return numObjects;
}

/*
* This function gets the number of objects obtained across the planets
* Parameters: none
* Return: int numObtainedObjects
*/
int Game::getNumObtainedObjects(){
    return numObtainedObj;
}


/*
* This function reads objects from a file
* Parameters: string filename
* Return: the number of objects in the file
*/
int Game::readObjects(string filename){
    numObjects=0;// (REPLACE ALL VALUES IN THIS ARRAY FOR EACH NEW PLANET)
    ifstream fileHandle;
    fileHandle.open(filename);
    if (fileHandle.is_open()){ //if it opens
        string list="";
        while (getline(fileHandle,list)){ //read a file of objects   [file format: objectName, objectValue]
            int size=2;
            string tempArray[size];
            char separator=',';
            int number= split(list, separator, tempArray, size); //splits each line
            
            if (numObjects==100){
                return numObjects;
            }
            
            //store the objects in the objects array
            objects[numObjects].setObjectName(tempArray[0]);    
            objects[numObjects].setObjectValue(stoi(tempArray[1])); //giving logic error (stoi)
            numObjects++;
        }
        return numObjects; //return the number of objects in the array
    }
    else{               //if file doesn't open then returns -1
        return -1;
    }
}

/*
* This function writes objects to another file
* Parameters: string filename
* Return: int totalValue (the total sum of obtained objects)
*/
int Game::writeObject(string filename){
    //Var
    int totalValue = 0;
    
    
    //look in objects array
    if(numObjects == 0){
        cout << "There are no objects in the objects array." << endl;
        
    //find the object that has the highest value score -- that is the object you are adding to the file
    } else {
        //Create most valued object to store data in
        Object valuedObject;
        
        //Find highest value
        int highestValue = objects[0].getObjectValue();
        string highestName = objects[0].getObjectName();
        for(int i=0; i < numObjects; i++){
            if(objects[i].getObjectValue() > highestValue){
                highestValue = objects[i].getObjectValue();
                highestName = objects[i].getObjectName();
            }
        }
        
        //Set object to be written to file
        valuedObject.setObjectValue(highestValue);
        valuedObject.setObjectName(highestName);
        
        //Add to objectsCollected Array
        objectsCollected[numObtainedObj].setObjectName(valuedObject.getObjectName());
        objectsCollected[numObtainedObj].setObjectValue(valuedObject.getObjectValue());
        
        //open "filename" to write to
        ofstream outFile;
        //write the object to the end of the file
        outFile.open(filename, ios::app);
        
        if(outFile.fail()){
            return -1;
        } else {
            outFile << valuedObject.getObjectName() << endl;
            outFile << valuedObject.getObjectValue() << endl;
        }
        
        outFile.close();
        
        cout << "You have added: " << valuedObject.getObjectName() << " with value " << valuedObject.getObjectValue() << endl;
        
        //read the same file
        ifstream inFile;
        inFile.open(filename);
        string line = "";
        
        if(inFile.fail()){
            return -1;
        } else {
            while(getline(inFile,line) && numObjects < 50){
                if(line != ""){
                    //If a digit, add to total
                    //calculate the total value of all objects in the list
                    if(isdigit(line[0])){
                        numObtainedObj += 1;
                        totalValue += stoi(line);
                        
                    } else {
                       continue;
                    }
                }
            }
        }
        inFile.close();
    }

    return totalValue;
}


/*
* This function gets the current planet
* Parameters: none
* Return: string planetOn
*/
string Game::getPlanet(){
    return planetOn;
}


/*
* This function sets the current planet
* Parameters: string planetOn_
* Return: none
*/
void Game::setPlanet(string planetOn_){
    planetOn = planetOn_;
}

/*
* This function checks to see if an object exists in the array
* Parameters: string objectName, int numObjects_, Object objectsArr[]
* Return: true or false
*/
bool findObject(string objectName, int numObjects_, Object objectsArr[]){
    //Find if user exists
    for(int i=0; i < numObjects_; i++){
        if(objectsArr[i].getObjectName() == objectName){
            return true;
        }
    }
    
    return false;
}


/*
* This function prints the object and value requested
* Parameters: string objectName_
* Return: none
*/
void Game::printObject(string objectName_){
    //find object in objects array
    if(!findObject(objectName_,numObjects,objects)){
        cout << "That object is not part of the list " << endl;
    } else {
        for(int i=0; i < numObjects; i++){
            if(objects[i].getObjectName() == objectName_){
                cout << "Object Name: " << objects[i].getObjectName() << ", Value: " << objects[i].getObjectValue() << endl;
            }
        }
    }
}


/*
* This function prints the stat of the current player
* Parameters: string playerName_
* Return: none
*/
void Game::printStats(string playerName_){
    if (numPlayers==0){
        cout<<"There are no players yet woopsies!"<<endl;
    }
    else{
        for (int i=0;i<50;i++){//find player in players array
            if (players[i].getName()== playerName_){
                
                //print intelligence, strength, money, and characterScore
                cout<<players[i].getName()<<"\nIntelligence: "<<players[i].getIntelligence()<<endl;
                cout<<"Strength: "<<players[i].getStrength()<<endl;
                cout<<"Money: "<< players[i].getMoney() <<endl;
                cout<<"Score: "<< players[i].calculateCharacterScore() <<endl;
                cout<<"Planet On: "<< getPlanet() << endl;
            }
        }
    }
}


/*
* This function returns the characterScore of the current player
* Parameters: string playerName_
* Return: none
*/
double Game::getCharStat(string playerName_){
    if (numPlayers==0){
        cout<<"There are no players yet woopsies!"<<endl;
    }
    else{
        for (int i=0;i<50;i++){//find player in players array
            if (players[i].getName()== playerName_){
                return players[i].calculateCharacterScore();

            }
        }
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

/*
* This function checks to see if a fighter exists in the array
* Parameters: string user, int numFighters_, Player fightersArr[]
* Return: index of that fighter
*/
int findFighter(string user, int numFighters_, Player fightersArr[]){
    //Find if user exists
    for(int i=0; i < numFighters_; i++){
        if(fightersArr[i].getName() == user){
            return i;
        }
    }
    
    return -1;
}


/*
* This function sets the current player being used
* Parameters: string playerName
* Return: none
*/
void Game::setCharacter(string playerName){
    //set character you want to use to perform tasks from character array
    if(findUser(playerName, numPlayers, players)){
        currentCharacter = playerName;
        cout << playerName << " is now your player." << endl;
    } else {
        cout << playerName << " is not part of the clan " << endl;
    }
}


/*
* This function gets the current player
* Parameters: string playerName
* Return: none
*/
string Game::getCurrentPlayer(){
    return currentCharacter;
}

/*
* This function adds a character to the Players array
* Parameters: string playerName
* Return: none
*/
void Game::addCharacter(string playerName){
    //adds character to character array at various planets
    if(numPlayers == 100){
        cout << "The players array is already full. " << playerName << " was not added." << endl;
    } else if (findUser(playerName, numPlayers, players)){
        cout << playerName << " already exists in the clan." << endl;
    } else {
        //add to clan
        Player new_player;
        
        //Find fighter
        int fightIndex = findFighter(playerName,numFighters,fighters);
        
        //Add username
        new_player.setName(playerName);
        
        //serach fighters array for player, add respective point values
        if(!(fightIndex == -1)){
            new_player.setIntelligence(fighters[fightIndex].getIntelligence());
            new_player.setStrength(fighters[fightIndex].getStrength());
            new_player.setMoney(fighters[fightIndex].getMoney());
            new_player.calculateCharacterScore();
        }
        
        //Add user to array
        players[numPlayers] = new_player;
        numPlayers++;
        
        cout << "Welcome to the clan, " << playerName << endl;
        
        //cout << players[numPlayers-1].getName() << ";" <<  players[numPlayers-1].getIntelligence() << ";" <<  players[numPlayers-1].getStrength() << ";" <<  players[numPlayers-1].getMoney() << endl;
        
    }
}



/*
* This function adds to the current player's intelligence score
* Parameters: int val-intelligence
* Return: none
*/
void Game::addIntelligence(int val){
    string player_name;
    int curr_intelligence;
    int new_intelligence;
    
    player_name = getCurrentPlayer();
    
    //Find player
    for (int i=0;i < numPlayers;i++){
        if (players[i].getName() == player_name) {
            //Get current intelligence
            curr_intelligence = players[i].getIntelligence();
            new_intelligence = curr_intelligence + val;
            //Set new intelligence
            players[i].setIntelligence(new_intelligence);
        }
    }
    
}
/*
* This function adds to the current player's strength score
* Parameters: int val- strength
* Return: none
*/
void Game:: addStrength(int val){
    string player_name;
    int curr_strength;
    int new_strength;
    
    player_name = getCurrentPlayer();
    
    //Find player
    for (int i=0;i < numPlayers;i++){
        if (players[i].getName() == player_name) {
            //Get current strength
            curr_strength = players[i].getStrength();
            new_strength = curr_strength + val;
            //Set new strength
            players[i].setStrength(new_strength);
        }
    }
}

/*
* This function calculates the probability of the player winning in a fight
* Parameters: fighterIndex- the index in players array of fighter
* Return: bool-true if the player wins, false if the player loses
*/
bool Game::fightTime(int fighterIndex){
    double probabilityWin;
    cout<<"Brave choice! It seems that " << fighters[fighterIndex].getName() << " wants to fight you!"<<endl;
    probabilityWin = ((1-(fighters[fighterIndex].getStrength())/100.0)*players[0].getStrength()/(double)fighters[fighterIndex].getStrength());
    if (probabilityWin>0.60){
        return true;
    }
    else{
        return false;
    }
}

/*
* This function takes and inputs fighters into a fighter array
* Parameters: filename-contains fighters name, intelligence, strength and money
* Return: int numFighters- the number of fighters in a list
*/
int Game:: readFighters(string filename){
    ifstream fileHandle;
    fileHandle.open(filename);
    if (fileHandle.is_open()){ //if it opens
        string list="";
        while (getline(fileHandle,list)){ //read a file of objects   [file format: objectName, objectValue]
            int size=4;
            string tempArray[size];
            char separator=',';
            int number= split(list, separator, tempArray, size); //splits each line
            
            //store the objects in the objects array
            fighters[numFighters].setName(tempArray[0]);    
            fighters[numFighters].setIntelligence(stoi(tempArray[1])); //giving logic error (stoi)
            fighters[numFighters].setStrength(stoi(tempArray[2])); //giving logic error (stoi)
            fighters[numFighters].setMoney(stoi(tempArray[3])); //giving logic error (stoi)
            numFighters++;
        }
        return numFighters;
    }
    else {
        return -1;
    }
}
/*
This program returns the money after gambling
parameters: moneyGambled-how much money the user gambles, randomPercent-a random percent to aplpy on money gambled, playerName-the player whose money you want to gamble.
returns: finalMoney- the money that player has at the end.
*/
double Game::gambleTime(double moneyGambled, int randomPercent, string playerName_){
    double finalMoney;
    bool moneySafe=false;
    if (findUser(playerName_, 50, players)) { //if user is found
        if (!moneySafe){
            for(int i=0;i<50;i++){
                if (playerName_==players[i].getName()){  //if you find the player in player array
                    if (moneyGambled<players[i].getMoney()){ //and if money gambled is less than what they have
                        moneySafe=true; 
                        finalMoney=moneyGambled*randomPercent/100 +players[i].getMoney();
                        cout<<"You won: "<< moneyGambled*randomPercent/100 << " spacecoins!"<<endl; //then calculate the money won, DOES NOT CALCULATE LOSSES
                        players[i].setMoney(finalMoney); //updates the new amount of money
                        cout<<"Your final money is "<< finalMoney <<endl;
                        return finalMoney;
                    }
                }
            }
            if (!moneySafe) {//if player didn't have enough money
                cout<<"Sorry you don't have that much money!"<<endl;
                for(int i=0;i<50;i++){
                    if (playerName_==players[i].getName()){  //if you find the player in player array
                        finalMoney= players[i].getMoney();
                        return finalMoney;
                    }
                }
            }
        }
    }
    else{
        cout<<"sorry that user doesn't exist!"<<endl;
        return 0; //returns 0 if there is no user
    }
}

/*
This program prints the money of the player
parameters: playerName_-the player whose money you want to know
returns: nothing
*/
void Game:: printMoney(string playerName_){
    if (numPlayers==0){
        cout<<"There are no players yet woopsies!"<<endl;
    }
    else{
        for (int i=0;i<50;i++){ //find player in players array
            if (players[i].getName()== playerName_){
                
                //print money
                cout<<players[i].getName()<<"\nMoney: "<< players[i].getMoney() <<endl;
            }
        }
    }
}


/*
This program returns the name of a player in fighters array
parameters: fighterIndex
returns: fighter name
*/
string Game:: returnName(int fighterIndex){
    return fighters[fighterIndex].getName();
}

/*
This program prints the end stats
parameters: none
returns: none
*/
void Game:: endStats(){
    for(int i=0; i < numPlayers; i++){
        cout << "Player: " << players[i].getName();
        for(int j=0; j < numObtainedObj; j++){
            if(i < numObtainedObj){
                cout << ", reward obtained: " << objectsCollected[j].getObjectName() << endl;
            } else {
                cout << ", reward obtained: none" << endl;
            }
            
        }
    }
}

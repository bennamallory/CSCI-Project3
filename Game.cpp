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
    numObtainedObj = 0;
    triviaQ = {"Elliptical galaxies are the most common type of galaxies in the universe (T/F)", "The hottest place in the universe is the Boomerang Nebula (T/F)", "The Universe is 13.8 billion years old (T/F)", "30 percent of the universe is dark matter (T/F)", "There are 8 planets in Earth's solar system (T/F)", "The largest planet in Earth's solar system is Mercury (T/F)", "A black hole has such a strong gravitational pull that even light cannot escape it (T/F)", "Proxima Centauri is the closest star to the sun (T/F)","The largest type of star in the universe is the protostar (T/F)","The white dwarf is the most common type of star in the universe (T/F)" };
    triviaA = {"T","F","T","F", "T","F", "T", "T", "F", "F"};
    mathQ = {"What is 5 + 5254 ?", "What is 2*10 ?", "What is 2 * 2 * 2 ?", "What is 10 squared?", "What is 50 / 2 ?", "What is 14-5*3", "What is 5*6/3-1 ?", "What is the square root of 9 multiplied by 2?", "What is the smallest factor of 12?", "What is 15 % 3 ?" };
    mathA = {5259, 20, 8, 100, 25, -1, 9, 6, 2, 0};
    
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
        
        //Add username
        new_player.setName(playerName);
        
        //Add user to array
        players[numPlayers] = new_player;
        numPlayers++;
        
        cout << "Welcome to the clan, " << playerName << endl;
    }
}


/*
* This function prints a trivia question and returns the answer
* Parameters: none
* Return: string triviaA[randNum]
*/
string Game::getTriviaQuestion(){
    //calculate a random number between 0 and 9
    Srand(time(0));
    int randNum = rand() % 9; 
    
    cout << triviaA[randNum] << endl;
    
    return triviaQ[randNum];
}


/*
* This function prints a math question and returns the answer
* Parameters: none
* Return: string mathA[randNum]
*/
int Game::getMathQuestion(){
    //calculate a random number between 0 and 9
    Srand(time(0));
    int randNum = rand() % 9; 
    
    cout << mathA[randNum] << endl;
    
    return mathQ[randNum];
}


/*
* This function prints a riddle question and returns the answer
* Parameters: none
* Return: string riddleA[randNum]
*/
string Game::getRiddleQuestion(){
    //calculate a random number between 0 and 9
    Srand(time(0));
    int randNum = rand() % 9; 
    
    cout << riddleA[randNum] << endl;
    
    return riddleAQ[randNum];
}

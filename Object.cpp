// CS1300 Spring 2020
// Author: Mallory Benna and Sravya Dhanwada
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Object Class Source File

#include <iostream> 
#include "Object.h"
using namespace std; 

//Default constructor
Object::Object(){
    objectName = "";
    objectValue = 0;
}

//Parameterized constructor
Object::Object(string objectName_, int objectValue_){
    objectName = objectName_;
    objectValue = objectValue_;
}


/*
* This function gets the name of the object
* Parameters: none
* Return: string objectName
*/
string Object::getObjectName(){
    return objectName;
}



/*
* This function gets the value of the object
* Parameters: none
* Return: int objectValue
*/
int Object::getObjectValue(){
    return objectValue;
}



/*
* This function sets the name of the object
* Parameters: string objectName_
* Return: none
*/
void Object::setObjectName(string objectName_){
    objectName = objectName_;
}


/*
* This function sets the value of the object
* Parameters: int objectValue_
* Return: none
*/
void Object::setObjectValue(int objectValue_){
    objectValue = objectValue_;
}

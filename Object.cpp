// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
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

//Getters
string Object::getObjectName(){
    return objectName;
}

int Object::getObjectValue(){
    return objectValue;
}

//Setters
void Object::setObjectName(string objectName_){
    objectName = objectName_;
}

void Object::setObjectValue(int objectValue_){
    objectValue = objectValue_;
}

// CS1300 Spring 2020
// Author: Mallory Benna and Srvya Dhanwanda
// Recitation: 106 – Sravanth Yajamanam
// Project 3 - Object Class

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream> 
using namespace std; 

class Object{
    public:
        Object(); //Default constructor
        Object(string objectName,int objectValue); //Parameterized constructor
        
        //Getters
        string getObjectName(); //get name of object
        int getObjectValue(); //get value score of object

        //Setters (void);
        void setObjectName(string objectName_); //set the name of the object
        void setObjectValue(int objectValue_); //set the value of the object

    private: 
        string objectName; //name of the object
        int objectValue; //the value score the object posesses 

}; 

#endif

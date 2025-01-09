#include <cmath>
#include <iostream>

#ifndef REEDSOLOMON_H
#define REEDSOLOMON_H

class ReedSolomon
{
private:
    //input data
    int numParityChecks; 
    int numSymbols;
    int numDataSymbols;

    //useful variables
    int size;
    char* arr;
    int qVal;

    //mapper arrays


    //helpful methods
    char* arrHelper(int size);
    int qValue(int t);
public:
    ReedSolomon(int a, int b); //constructor for now
    ~ReedSolomon(); //destructor
    unsigned int FieldSize(int q) const; //this takes in the value of bitChecks computes the Galois Field Size

    //make the polynomial that stores the data
    void Polynomial();
    unsigned int tValue(int e) const;
    //getters
    int getNumSymbols();
    int getParityChecks();
    int getNumDataSymbols();

    void Print();
};

#endif

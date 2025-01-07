#include <cmath>
#include <iostream>

#ifndef REEDSOLOMON_H
#define REEDSOLOMON_H

class ReedSolomon
{
private:
    static int numParityChecks; //constant for the object we declare
    static int numSymbols;
    static int numDataSymbols;
    int size;
    int* arr;
    int* arrHelper(int size);
public:
    ReedSolomon(int a, int b); //constructor for now
    ~ReedSolomon(); //destructor
    unsigned int FieldSize() const; //this takes in the value of bitChecks computes the Galois Field Size



    //getters
    int getNumSymbols();
    int getParityChecks();
    int getNumDataSymbols();

    void Print();
};

#endif

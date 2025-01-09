#include "ReedSolomon.h"
#include <cmath>
#include <iostream>

// basic constructor (will implement more later)
// follows RS(a,b) form
ReedSolomon::ReedSolomon(int a, int b) {
    this->numSymbols = a;
    this->numDataSymbols = b; //assign the static ints

    //number of parity checks
    this->numParityChecks = numSymbols - numDataSymbols;

    size = FieldSize(b); //use the helper (maybe make this private?)
    arr = arrHelper(size);
}
//destructor
ReedSolomon::~ReedSolomon() {
    delete[] arr; //delete the dynamic array
}

//assumes the size of the array we will output just alloting the memory for it

char* ReedSolomon::arrHelper(int size) {
    char* arr = new char[size];
    return arr;
}

void ReedSolomon::Print() {
    std::cout << size << std::endl;

    for (int i = 0; i < this->size; i++)
    {
        arr[i] = 1;
        std::cout << arr[i] << std::endl;
    }

    //std::cout << FieldSize() << std::endl;
    std::cout << getParityChecks() << std::endl;
    std::cout << getNumDataSymbols() << std::endl;
    std::cout << getNumSymbols() << std::endl;
}

//constant because this must not change
unsigned int ReedSolomon::FieldSize(int t) const {
    unsigned int fieldSize = 0; //needs to be an integer becaue
    fieldSize = std::pow(2, t);
    return fieldSize;
}

//gets the t value (ie distance factor)
//takes in number of errors to find the min distance
unsigned int ReedSolomon::tValue(int e) const {
    unsigned int t = 2*e + 1;
    return t;
}



/**********************
* take array as an input
* this is the array that looks at the data
* in this array, per element multiply to a power
**********************/
void ReedSolomon::Polynomial() {

}

//getter for bit checker
int ReedSolomon::getParityChecks() {
    return this->numParityChecks;
}

//getter for number of symbols
int ReedSolomon::getNumSymbols() {
    return this->numSymbols;
}

//getter for datasymbols
int ReedSolomon::getNumDataSymbols() {
    return this->numDataSymbols;
}
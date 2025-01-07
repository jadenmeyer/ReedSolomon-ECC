#include "ReedSolomon.h"
#include <cmath>
#include <iostream>

int ReedSolomon::numParityChecks = 0;
int ReedSolomon::numSymbols = 0;
int ReedSolomon::numDataSymbols = 0;

// basic constructor (will implement more later)
// follows RS(a,b) form
ReedSolomon::ReedSolomon(int a, int b) {
    this->numSymbols = a;
    this->numDataSymbols = b; //assign the static ints

    //number of parity checks
    this->numParityChecks = numSymbols - numDataSymbols;

    size = FieldSize(); //use the helper (maybe make this private?)
    arr = arrHelper(size);
}
//destructor
ReedSolomon::~ReedSolomon() {
    delete[] arr; //delete the dynamic array
}

//assumes the size of the array we will output just alloting the memory for it

int* ReedSolomon::arrHelper(int size) {
    int* arr = new int[size];
    return arr;
}

void ReedSolomon::Print() {
    std::cout << size << std::endl;

    for (int i = 0; i < this->size; i++)
    {
        arr[i] = 1;
        std::cout << arr[i] << std::endl;
    }

    std::cout << FieldSize() << std::endl;
    std::cout << getParityChecks() << std::endl;
    std::cout << getNumDataSymbols() << std::endl;
    std::cout << getNumSymbols() << std::endl;
}

//constant because this must not change
unsigned int ReedSolomon::FieldSize() const {
    unsigned int fieldSize = 0; //needs to be an integer becaue
    fieldSize = std::pow(2, numDataSymbols); //compute the power (2 because bit checks mod 2 arithmetic)
    return fieldSize;
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
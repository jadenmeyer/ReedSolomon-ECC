#include <iostream>
#include <cmath>
#include "ReedSolomon.h"


int main() {
    std::cout << "Hello World" << std::endl;
    //code to look at noisy channels for ECC probably
    ReedSolomon reed(7,3);
    
    reed.Print();
    
    return 0;
} 
#include "NewRS.h"
#include <cstdint>
#include <cmath>
#include <iostream>
/*
*=====================
*Constructors and Destructors
*=====================
*/
NewRS::NewRS(int q) {
    //std::cout << primitiveRootFinder(q) << std::endl;
    primitiveRootFinder(q);
}

NewRS::~NewRS() {
    delete[] MODARRAY;
}
/*
*=====================
*Helper Methods (priv)
*=====================
*/

uint_fast8_t NewRS::primitiveRootFinder(uint_fast8_t q) {
    uint_fast8_t primRoot = 0;
    uint_fast8_t root;
    if(q > MAX_FIELD_SIZE) {
        return -1;
    }
    //max of 256 because Galois Field
    //start at 2 because 1 is trivial and 0 does nothing
    for(int i = 2; i < q; i++) {
        root = i;
        if (isPrimRoot(root, q) == true) {
            primRoot = root;
            break;
        }
        else {
            continue;
        }
    }
    if(primRoot == 0) {
        std::cout << "Error in size" << std::endl;
        return -1;
    }
    return primRoot;
}

bool NewRS::isPrimRoot(uint_fast8_t r, uint_fast8_t q) {

    bool result = false;
    uint_fast8_t val;

    for(uint_fast8_t j = 0; j < q; j++) {
            val = static_cast<uint_fast8_t>(std::pow(r, j)) % q; //casting because pow returns a double    
            //want non zeroes
            if(val == 0) {
                result = false;
                break;
            }

            bool foundInArray = false;
            for (size_t i = 0; i < sizeof(MODARRAY)/sizeof(MODARRAY[0]); i++) {
            if (val == MODARRAY[i]) {
                foundInArray = true;
                break;
            }
        }

        // If val is not in the array, stop and return false
        if (!foundInArray) {
            result = false;
            break;
        }
            
    }

    return result;
}

void NewRS::fieldValues(uint_fast8_t q) {
    MODARRAY = new uint_fast8_t[q]; //dynamic array

    if(q > MAX_FIELD_SIZE) {
        std::cout << "exceeded maximum Field Size" << std::endl;
        return;
    }
    for(int i = 0; i < q; i++){
        MODARRAY[i] = i;
    }
    
}
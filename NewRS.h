#include <cstdint>
#ifndef NewRS_H
#define NewRS_H

class NewRS
{
private:
    static const uint_fast8_t MAX_FIELD_SIZE = 256; //const to tel if out of bounds
    uint_fast8_t* MODARRAY;
    void fieldValues(uint_fast8_t q);
    uint_fast8_t primitiveRootFinder(uint_fast8_t q); //loop that iterates over the field
    bool isPrimRoot(uint_fast8_t r, uint_fast8_t q); //called in primRootFinder to check if a prim root
    
public:
    NewRS(int q);
    ~NewRS();
};



#endif
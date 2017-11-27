#pragma once
#include "Instruccion.h"
#include "JMP.h"

class BRA : public JMP {
public:
    BRA();
    BRA(const BRA& orig);
    virtual ~BRA();    
private:

};
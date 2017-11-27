#pragma once

#include "Instruccion.h"
#include "Registro.h"

class SB: public Instruccion {
public:
    SB();
    SB(const SB& orig);
    virtual ~SB();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
};

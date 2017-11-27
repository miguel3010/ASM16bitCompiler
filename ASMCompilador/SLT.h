#pragma once

#include "Instruccion.h"
#include "Registro.h"
class SLT: public Instruccion {
public:
    SLT();
    SLT(const SLT& orig);
    virtual ~SLT();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;

};

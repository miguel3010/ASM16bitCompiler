#pragma once
#include "Instruccion.h"
#include "Registro.h"
class LB : public Instruccion {
public:
    LB();
    LB(const LB& orig);
    virtual ~LB();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
};
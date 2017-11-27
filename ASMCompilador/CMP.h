#pragma once
#include "Instruccion.h"
#include "Registro.h"
#include "Parametro.h"

class CMP: public Instruccion {
public:
    CMP();
    CMP(const CMP& orig);
    virtual ~CMP();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
};
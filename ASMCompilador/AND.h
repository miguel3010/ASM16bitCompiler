#pragma once
#include "Instruccion.h"
#include "Registro.h"
#include "Parametro.h"

class AND : public Instruccion {
public:
    AND();
    AND(const AND& orig);
    virtual ~AND();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
    Registro *R3;
};
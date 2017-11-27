#pragma once

#include "Instruccion.h"
#include "Registro.h"
#include "Parametro.h"

class SL : public Instruccion {
public:
    SL();
    SL(const SL& orig);
    virtual ~SL();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
};

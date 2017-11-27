#pragma once
#include "Instruccion.h"
#include "Registro.h"
#include "Numero.h"

class LI: public Instruccion {
public:
    LI();
    LI(const LI& orig);
    virtual ~LI();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Numero *N1;
};
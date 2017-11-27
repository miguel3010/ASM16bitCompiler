#pragma once

#include "Instruccion.h"
#include "Registro.h"
#include "Parametro.h"

class ADD : public Instruccion {
public:
    ADD();
    ADD(const ADD& orig);
    virtual ~ADD();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);

private:
    Registro *R1;
    Registro *R2;
    Registro *R3;

};
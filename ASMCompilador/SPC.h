#pragma once

#include "Instruccion.h"
#include "Registro.h"

class SPC : public Instruccion {
public:
    SPC();
    SPC(const SPC& orig);
    virtual ~SPC();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
   
private:
    Registro *R1;
};
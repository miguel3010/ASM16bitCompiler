#pragma once
#include "Instruccion.h"
#include "Registro.h"

class SUB : public Instruccion {
public:
    SUB();
    SUB(const SUB& orig);
    virtual ~SUB();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
    Registro *R3;
};

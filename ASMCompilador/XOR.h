#pragma once
#include "Instruccion.h"
#include "Parametro.h"
#include "Registro.h"

class XOR : public Instruccion {
public:
    XOR();
    XOR(const XOR& orig);
    virtual ~XOR();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Registro *R2;
    Registro *R3;
};
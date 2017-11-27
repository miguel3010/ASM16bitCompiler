#pragma once

#include "Compilable.h"
#include "Parametro.h"
#include "Error.h"

class Instruccion : public Compilable {
public:
    Instruccion();
    Instruccion(const Instruccion& orig);
    virtual ~Instruccion();
    virtual char* getHex() = 0;
    virtual bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3)=0;
    virtual Error* getError();
protected:
    int opcode;     
    Error* err;
};
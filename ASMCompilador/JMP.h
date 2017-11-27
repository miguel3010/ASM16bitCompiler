#pragma once

#include "Instruccion.h"
class JMP : public Instruccion{
public:
    JMP();
    JMP(const JMP& orig);
    virtual ~JMP();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Instruccion *R1;

};
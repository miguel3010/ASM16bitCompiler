#pragma once
#include "Instruccion.h"
#include "Registro.h"

class JR : public Instruccion{
public:
    JR();
    JR(const JR& orig);
    virtual ~JR();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
    
private:
    Registro *R1;

};

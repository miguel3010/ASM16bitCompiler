#pragma once
#include "Instruccion.h"
#include "Registro.h"
#include "Numero.h"
class LUI : public Instruccion{
public:
    LUI();
    LUI(const LUI& orig);
    virtual ~LUI();
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
private:
    Registro *R1;
    Numero *R2;
     

};
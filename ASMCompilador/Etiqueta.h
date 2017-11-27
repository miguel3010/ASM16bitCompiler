#pragma once
#include "Parametro.h"
#include "Instruccion.h"
#include <string.h>
#include <string>

class Etiqueta : public Instruccion {
public:

    std::string Label;
    int PC;
    Etiqueta();
    Etiqueta(const Etiqueta& orig);
    char* getHex();
    bool buildInstruccion(Parametro *p1, Parametro *p2, Parametro *p3);
    virtual ~Etiqueta();
private:

};
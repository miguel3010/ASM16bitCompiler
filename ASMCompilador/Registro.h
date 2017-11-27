#pragma once

#include "Parametro.h"

class Registro : public Parametro {
public:
    int Rnum;
    Registro();
    Registro(const Registro& orig);
    virtual ~Registro();
    bool buildParametro(char *c);
    char* getHex();
private:
int getNumberRegit(char* c);
};
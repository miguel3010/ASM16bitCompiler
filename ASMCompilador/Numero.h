#pragma once

#include "Parametro.h"


class Numero : public Parametro {
public:
    
    int Num;
    
    Numero();
    Numero(const Numero& orig);
    virtual ~Numero();
     bool buildParametro(char *c);
    char* getHex();
private:

};
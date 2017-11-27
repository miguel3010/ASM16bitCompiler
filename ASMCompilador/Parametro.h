#pragma once

#include "Compilable.h"
#include "Error.h"

class Parametro : virtual public Compilable {
public:
    Parametro();
    Parametro(const Parametro& orig);
    virtual ~Parametro();
    virtual bool buildParametro(char *c) = 0;
    virtual char* getHex() = 0;
    virtual Error* getError();
private:
protected:
    Error *err;

};
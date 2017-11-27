#pragma once

#include "Instruccion.h"
#include <string.h>
#include <string>
class InstruccionFactory {
public:
    InstruccionFactory();
    InstruccionFactory(const InstruccionFactory& orig);
    virtual ~InstruccionFactory();
    Instruccion* getInstruccion(std::string c);
//    virtual char* getHex();
private:
    Instruccion* validInstruccion(std::string c);

};
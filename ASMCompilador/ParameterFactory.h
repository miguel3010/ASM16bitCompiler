#pragma once

#include "Parametro.h"
#include <string>
#include <string.h>

class ParameterFactory {
public:
    ParameterFactory();
    ParameterFactory(const ParameterFactory& orig);
    virtual ~ParameterFactory();
    Parametro* getParameter(std::string c);
private:
    bool isNumero(std::string c);
    bool isRegistro(std::string c);
    bool isEtiqueta(std::string c); 
};

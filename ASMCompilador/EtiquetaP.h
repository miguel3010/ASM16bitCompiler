#pragma once

#include "Etiqueta.h"

class EtiquetaP : public Parametro {
public:
    EtiquetaP();
    EtiquetaP(const EtiquetaP& orig);
    virtual ~EtiquetaP();
    Etiqueta* etiqueta;
    bool buildParametro(char *c);
    char* getHex();
private:

};
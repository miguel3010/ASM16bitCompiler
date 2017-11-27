#pragma once

#include "Etiqueta.h"
#include "EtiquetaP.h"
#include "Error.h"
#include <list>

class LabelManager {
public:
    static LabelManager* getInstance();
    virtual ~LabelManager();
    EtiquetaP* getEtiquetaParametro(std::string et);
    bool RegistrarEtiruetaInstruccion(std::string et, int PC);
    bool errorAnalyce();
    Etiqueta* getEtiqueta(std::string et);
    std::list<Error*> getErrores();
	void borrarTodaEtiqueta();
	void reset();
private:
    static LabelManager* instance;
    std::list<Etiqueta*> etiquetas;
    std::list<Error*> err;
    LabelManager();
     
};
#include "stdafx.h"
#include "ParameterFactory.h"


#include <string>
#include <string.h>
#include "Util.h"
#include <math.h>
#include "Registro.h"
#include "Numero.h"
#include "EtiquetaP.h"
#include "LabelManager.h"

ParameterFactory::ParameterFactory() {
}

ParameterFactory::ParameterFactory(const ParameterFactory& orig) {
}

ParameterFactory::~ParameterFactory() {
}

Parametro* ParameterFactory::getParameter(std::string c) {
    if (isNumero(c)) {
        return new Numero();
    } else if (isRegistro(c)) {
        return new Registro();
    } else if (isEtiqueta(c)) {
        LabelManager *lb = LabelManager::getInstance();
        EtiquetaP *etq = lb->getEtiquetaParametro(c);
        return etq;
    }
    return nullptr;

}

/**
 * 
 * @param c
 * @return 
 */
bool ParameterFactory::isNumero(std::string c) {
    if (c != "") {
        try {
            int numero = Util::parseInt((char*) c.c_str());
            return true;
        } catch (std::exception e) {
        }
    }
    return false;
}

/**
 * 
 * @param c
 * @return 
 */
bool ParameterFactory::isRegistro(std::string c) {
    if (c != "") {
        if (c[0] == 'R') {
            std::string str2 = c.substr(1, c.size() - 1);
            try {
                int i = Util::parseInt((char*) str2.c_str());
                if (i >= 0) {
                    return true;
                }
            } catch (std::exception e) {
            }
        }
    }
    return false;
}

bool ParameterFactory::isEtiqueta(std::string c) {
    if (c != "") {
        int l = c.length();
        if (!Util::specialEti(c[0])) {
            return true;
        }
    }
    return false;
}
#include "stdafx.h"
#include "EtiquetaP.h"

#include <stdio.h>

EtiquetaP::EtiquetaP() : Parametro() {
}

EtiquetaP::EtiquetaP(const EtiquetaP& orig) {
}

EtiquetaP::~EtiquetaP() {
}

bool EtiquetaP::buildParametro(char *c) {
    return true;
}

char* EtiquetaP::getHex() {
    if (etiqueta && etiqueta->PC >= 0) {
        char *hex;
        if (etiqueta->PC > 15) {
            hex = new char[2];
            hex[2] = 0;
            sprintf(hex, "%x", etiqueta->PC); //transforma a hexadecimal
        } else {
            hex = new char[1];
            sprintf(&hex[0], "%x", etiqueta->PC); //transforma a hexadecimal
            hex[1] = 0;
        }
        return hex;
    }
    return nullptr;
}

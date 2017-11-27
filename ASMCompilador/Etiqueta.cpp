#include "stdafx.h"
#include "Etiqueta.h"


#include <stdio.h> 

Etiqueta::Etiqueta() : Instruccion() {
    PC = -1;
}

Etiqueta::Etiqueta(const Etiqueta& orig) {
}

Etiqueta::~Etiqueta() {
}

bool Etiqueta::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    return false;
}

char* Etiqueta::getHex() {
    if (PC > -1) {
        char *hex = new char[4];
        hex[4] = 0;
        hex[0] = 'c';
        hex[1] = '0';
        if (PC > 15) {
            sprintf(&hex[2], "%x", PC + 1); //transforma a hexadecimal  
        } else {
            //transforma a hexadecimal  
            hex[2] = '0';
            sprintf(&hex[3], "%x", PC + 1);

        }

        return hex;
    }
    return nullptr;
}

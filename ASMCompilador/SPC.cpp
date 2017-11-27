#include "stdafx.h"
#include "SPC.h"

#include <stddef.h>
#include <stdio.h>
#include "Registro.h"
#include <math.h>

SPC::SPC() {
    opcode = 15;
}

SPC::SPC(const SPC& orig) {
}

SPC::~SPC() {
    if (R1) {
        delete R1;
    }
}

char* SPC::getHex() {
    if (R1 != nullptr) {
        char* hex = new char[4];
        sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
        hex[1] = *R1->getHex();
        sprintf(&hex[2], "%x", 0);
        sprintf(&hex[3], "%x", 0);
        hex[4] = 0;
        return hex;
    }
    return nullptr; 
}

bool SPC::buildInstruccion(Parametro *p1, Parametro *p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (p3 == nullptr && p2 == nullptr) {
            R1 = r1;
            return true;
        }

        if (!R1) {
            err = new Error();
           
            err->setdescripcion("La instruccion SPC toma solo un registro como parametros.");
        }
        return false;
    } 
}
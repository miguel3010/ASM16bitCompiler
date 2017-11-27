#include "stdafx.h"
#include "SB.h"


#include <stddef.h>
#include <stdio.h>
#include "Registro.h" 
#include <math.h>
SB::SB() {
    opcode = 8;
}

SB::SB(const SB& orig) {
}

SB::~SB() {
    if (R1) {
        delete R1;
    }
    if (R2) {
        delete R2;
    }
}

char* SB::getHex() {
    if (R1 != nullptr) {
        char* hex = new char[4];
        sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
        sprintf(&hex[1], "%x", 0);
        hex[2] = *R1->getHex();
        hex[3] = *R2->getHex();
        hex[4] = 0;
        return hex;
    }
    return nullptr;

}

bool SB::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (Registro * r2 = dynamic_cast<Registro*> (p2)) {
            R1 = r1;
            R2 = r2;
            return true;
        }
    }
    if (!R1 && !R2) {
        err = new Error();
        
        err->setdescripcion("La instruccion SB toma tres registros como parametros.");
    }
    return false;
}
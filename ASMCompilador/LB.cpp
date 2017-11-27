#include "stdafx.h"
#include "LB.h"



#include <stddef.h>
#include <stdio.h>
#include "Registro.h" 
#include <math.h>

LB::LB() {
    opcode = 9;
}

LB::LB(const LB& orig) {
}

LB::~LB() {
    if (R1) {
        delete R1;
    }
    if (R2) {
        delete R2;
    }
}

char* LB::getHex() {
    if (R1 != nullptr) {
        char* hex = new char[4];

        sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
        hex[1] = *R1->getHex();
        hex[2] = *R2->getHex();
        sprintf(&hex[3], "%x", 0);
        hex[4] = 0;
        return hex;
    }
    return nullptr;
}

bool LB::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (Registro * r2 = dynamic_cast<Registro*> (p2)) {
            R1 = r1;
            R2 = r2;
            return true;

        }
    }
    if (!R1 && !R2) {
        err = new Error();
        
        err->setdescripcion("La instruccion SB toma dos registros como parametros.");
    }
    return false;
}
#include "stdafx.h"
#include "JR.h"


#include <stddef.h>
#include <stdio.h>
#include "Registro.h"
#include <math.h>

JR::JR() {
    opcode = 14;
}

JR::JR(const JR& orig) {
}

JR::~JR() {
    if (R1) {
        delete R1;
    }
}

char* JR::getHex() {
    if (R1 != nullptr) {
        char* hex = new char[4];
        sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
        sprintf(&hex[1], "%x", 0);
        hex[2] = *R1->getHex();
        sprintf(&hex[3], "%x", 0);
        hex[4] = 0;
        return hex;
    }
    return nullptr; 
}

bool JR::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (p3 == nullptr && p2 == nullptr) {
            R1 = r1;
            return true;
        }

        if (!R1) {
            err = new Error();
            
            err->setdescripcion("La instruccion LUI toma un registro y un numero como parametros.");
        }
        return false;
    } 
}
#include "stdafx.h"
#include "CMP.h"



#include <stddef.h>
#include <stdio.h>
#include "Registro.h" 
#include <math.h>
CMP::CMP() {
    opcode = 7;
}

CMP::CMP(const CMP& orig) {
}

CMP::~CMP() {
    if (R1) {
        delete R1;
    }
    if (R2) {
        delete R2;
    }
}

char* CMP::getHex() {
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

bool CMP::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (Registro * r2 = dynamic_cast<Registro*> (p2)) {
            R1 = r1;
            R2 = r2;
            return true;
        }
    }
    if (!R1 && !R2 ) {
        err = new Error();         
        err->setdescripcion("La instruccion CMP toma dos registros como parametros.");
    }
    return false;
}
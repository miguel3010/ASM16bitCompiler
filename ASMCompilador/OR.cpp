#include "stdafx.h"
#include "OR.h"



#include <stddef.h>
#include <stdio.h>
#include "Registro.h" 
#include <math.h>
OR::OR() {
      opcode = 3;
}

OR::OR(const OR& orig) {
}

OR::~OR() {
    if(R1){delete R1;}
    if(R2){delete R2;}
    if(R3){delete R3;}
}

char* OR::getHex() {
    if (R1 != nullptr) {
        char* hex = new char[4];        
        sprintf(&hex[0], "%x", opcode);//transforma a hexadecimal         
        hex[1] = *R1->getHex();
        hex[2] = *R2->getHex();
        hex[3] = *R3->getHex();
        hex[4] = 0;
        return hex;
    }
    return nullptr;
}

bool OR::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {

    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (Registro * r2 = dynamic_cast<Registro*> (p2)) {
            if (Registro * r3 = dynamic_cast<Registro*> (p3)) {
                R1 = r1;
                R2 = r2;
                R3 = r3;
                return true;
            }
        }
    }
    if (!R1 && !R2 && !R3) {
        err = new Error();       
        err->setdescripcion("La instruccion OR toma tres registros como parametros.");
    }
    return false;
}
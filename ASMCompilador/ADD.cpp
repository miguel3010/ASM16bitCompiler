#include "stdafx.h"
#include "ADD.h"


#include <stddef.h>
#include <stdio.h>
#include "Registro.h" 
#include <math.h>

ADD::ADD() {
     opcode = 0;
	 R1 = nullptr;
	 R2 = nullptr;
	 R3 = nullptr;
}

ADD::ADD(const ADD& orig) {
	
   
}

ADD::~ADD() {
    if(R1){delete R1;}
    if(R2){delete R2;}
    if(R3){delete R3;}
}

char* ADD::getHex() {
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

bool ADD::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {

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
        err->setdescripcion("La instruccion ADD toma tres registros como parametros.");
    }
    return false;
}
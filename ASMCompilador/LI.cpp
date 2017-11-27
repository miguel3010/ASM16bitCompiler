#include "stdafx.h"
#include "LI.h"



#include "Instruccion.h"
#include "Registro.h"
#include "Numero.h"
#include <stddef.h>
#include <stdio.h> 
#include <math.h>
#include "Util.h"
LI::LI() {
    opcode = 10;
}

LI::LI(const LI& orig) {
}

LI::~LI() {
    if (R1) {
        delete R1;
    }
    if (N1) {
        delete N1;
    }
}

char* LI::getHex() {
	if (R1 != nullptr) {
		char* hex = new char[4];
		hex[4] = 0;
		sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
		//sprintf(&hex[1], "%x", 0); //transforma a hexadecimal
		hex[1] = *R1->getHex();
		char *j = nullptr;

		j = ((Numero*)N1)->getHex();


		if (Util::getLength(j) < 2) {
			hex[2] = '0';
			hex[3] = j[0];
		}
		else {
			hex[2] = j[0];
			hex[3] = j[1];
		}

		return hex;
	}
	return nullptr;
}

bool LI::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (Numero * r2 = dynamic_cast<Numero*> (p2)) {
            if (r2->Num >= 0 && r2->Num <= 255) {
                R1 = r1;
                N1 = r2;
                return true;
            } else {
                err = new Error();              
                err->setdescripcion("El numero superó el numero de bits(max 15)");
            }
            
        }
    }
    if (!R1 && !N1) {
        err = new Error();        
        err->setdescripcion("La instruccion LI toma dos registros como parametros.");
    }
    return false;
}
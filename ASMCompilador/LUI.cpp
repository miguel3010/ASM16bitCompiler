#include "stdafx.h"
#include "LUI.h"


#include <stddef.h>
#include <stdio.h>
#include "Registro.h"
#include "ParameterFactory.h"
#include <math.h>
#include "Util.h"

LUI::LUI() {
    opcode = 11;
}

LUI::LUI(const LUI& orig) {
}

LUI::~LUI() {
    if (R1) {
        delete R1;
    }
    if (R2) {
        delete R2;
    }
}

char* LUI::getHex() {
	if (R1 != nullptr) {
		char* hex = new char[4];
		hex[4] = 0;
		sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
		//sprintf(&hex[1], "%x", 0); //transforma a hexadecimal  
		hex[1] = *R1->getHex();
		char *j = nullptr;
		j = ((Numero*)R2)->getHex();
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

bool LUI::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
    if (Registro * r1 = dynamic_cast<Registro*> (p1)) {
        if (Numero * r2 = dynamic_cast<Numero*> (p2)) {
            if (p3 == nullptr) {
				if (r2->Num >= 0 && r2->Num <= 255){
					R1 = r1;
					R2 = r2;
					return true;
				}else {
					err = new Error();
					err->setdescripcion("El numero superó el numero de bits(max 15)");
				}
                
            }
        }
        if (!R1 && !R2) {
            err = new Error();
            
            err->setdescripcion("La instruccion LUI toma un registro y un numero como parametros.");
        }
        return false;
    }
}
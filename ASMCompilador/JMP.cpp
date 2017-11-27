#include "stdafx.h"
#include "JMP.h"

#include <stddef.h>
#include <stdio.h>
#include "Registro.h"
#include "EtiquetaP.h"
#include "Numero.h"
#include <math.h>
#include "Util.h"

JMP::JMP() {
	opcode = 12;
}

JMP::JMP(const JMP& orig) {
}

JMP::~JMP() {
	if (R1) {
		delete R1;
	}
}

char* JMP::getHex() {
	if (R1 != nullptr) {
		char* hex = new char[4];
		hex[4]=0;
		sprintf(&hex[0], "%x", opcode); //transforma a hexadecimal         
		sprintf(&hex[1], "%x", 0); //transforma a hexadecimal  
		char *j = nullptr;
		
		j=((EtiquetaP*)R1)->getHex();
		
		
		if (Util::getLength(j) < 2) {
			hex[2] = '0';
			hex[3]='4';
			hex[3]=j[0];
		} else {
			hex[2] = j[0];
			hex[3] = j[1];
		}

		return hex;
	}
	return nullptr;
}

bool JMP::buildInstruccion(Parametro* p1, Parametro* p2, Parametro* p3) {
	if (Numero * r1 = dynamic_cast<Numero*> (p1)) {
		if (r1->Num >= 0 && r1->Num <= 255) {
			R1 = (Instruccion*) r1;
			return true;
		}
	} else if (EtiquetaP * r1 = dynamic_cast<EtiquetaP*> (p1)) {
		R1 = (Instruccion*) r1;
		return true;
	}
	if (!R1) {
		err = new Error();        
		err->setdescripcion("La instruccion JMP toma un numero o una etiqueta como parametro.");
	}
	return false;

}
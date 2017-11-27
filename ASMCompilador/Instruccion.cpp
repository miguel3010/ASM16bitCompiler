#include "stdafx.h"
#include "Instruccion.h"



#include "Instruccion.h"

Instruccion::Instruccion() : Compilable() {
    opcode = -1;
	err = nullptr;
}

Instruccion::Instruccion(const Instruccion& orig) {
}

Instruccion::~Instruccion() {
    if (err) {
        delete err;
    }
}

Error* Instruccion::getError() {
    return err;
}

#include "stdafx.h"
#include "Error.h"


#include "Error.h"
#include "Instruccion.h"
#include <string>
#include <string.h>
#include <sstream>

Error::Error() {
    PC = -1;
}

Error::Error(const Error& orig) {
}

Error::~Error() {
}

void Error::setdescripcion(std::string e) {
    this->desc = e;
}

std::string Error::getDescripcion() {
    return desc;
}

int Error::getLinea() {
    return PC;
}

void Error::setLinea(int l) {
    if (l >= 0) {
        PC = l;
    }
}

std::string Error::ToString() {
    if (!desc.empty()) {
        std::string error;

        if (PC>-1) {
            std::stringstream ss;
            ss << PC;
            error = "[Linea " + ss.str() + "] ";
        }
        error += "ERROR:  " + desc;
        return error;
    }
    return "";
}
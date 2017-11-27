#include "stdafx.h"
#include "Numero.h"



#include <stddef.h>
#include <string.h>

#include "Numero.h"
#include "Util.h"
#include <math.h>

Numero::Numero() {
    Num = -1;
}

Numero::Numero(const Numero& orig) {
}

Numero::~Numero() {
}

bool Numero::buildParametro(char *c) {

    try {
        Num = Util::parseInt(c);
        if (Num<-255 && Num > 255) {
            err = new Error();
            string er(c);
            err->setdescripcion(er + " es un numero demasiado grande para esta arquitectura x16");
        }
        return true;
    } catch (std::exception) {
        err = new Error();
        string er(c);
        err->setdescripcion("La sentencia '" + er + "' no representa un numero");
    }

    return false;
}

char* Numero::getHex() {
    if (Num >= 0 && Num <= 15) {
        char *hex = new char[1];
        sprintf(hex, "%x", Num); //transforma a hexadecimal
        hex[1] = 0;
        return hex;
    } else if (Num >= 0 && Num <= 255) {
        char *hex = new char[2];
        sprintf(hex, "%x", Num); //transforma a hexadecimal
        hex[2] = 0;
        return hex;
    }
    return nullptr;
}


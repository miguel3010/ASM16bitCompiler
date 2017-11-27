#include "stdafx.h"
#include "Registro.h"

#include "Util.h"
#include <math.h>

Registro::Registro() {
    Rnum = -1;
}

Registro::Registro(const Registro& orig) {
}

Registro::~Registro() {
}

bool Registro::buildParametro(char *c) {
    int r = getNumberRegit(c);
    if (r >= 0 && r <= 15) {
        Rnum = r;
        return true;
    } else {
        err = new Error();
        string er(c);
        err->setdescripcion("Los registros permitidos debe estar entre 0 y 15, '" + er + "' Registro no valido.");

    }
    return false;
}

char* Registro::getHex() {
    char *hex = new char[1];
    sprintf(hex, "%x", Rnum); //transforma a hexadecimal
    hex[1] = 0;
    return hex;
}

int Registro::getNumberRegit(char* c) {
    int r = -1;
    if (c) {
        int l = Util::getLength(c);
        if (c[0] == 'R') {
            if (l > 1 && l < 4) {
                int i = l - 1, e = 0;
                double p = 0;
                while (i > 0) {
                    if (!Util::specialChar(c[i])) {
                        int m = (((int) c[i]) - 48);
                        p += m * pow(10, e);
                        e = --i;
                    } else {
                        p = -1;
                        break;
                    }
                }
				if (p >= 0.0 && p <= 15.0) {
                    return (int) p;
                }

            }
        }
    }
    return r;
}
#include "stdafx.h"
#include "Parametro.h"


Parametro::Parametro() {
}

Parametro::Parametro(const Parametro& orig) {
}

Parametro::~Parametro() {
}

Error* Parametro::getError(){
    return err;
}
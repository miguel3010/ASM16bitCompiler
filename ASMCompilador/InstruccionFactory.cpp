#include "stdafx.h"
#include "InstruccionFactory.h"



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


#include "AND.h"
#include "BRA.h"
#include "CMP.h"
#include "JMP.h" 
#include "JR.h"
#include "LB.h"
#include "LI.h"
#include "LUI.h"
#include "SB.h"
#include "SL.h"
#include "SLT.h"
#include "SUB.h"
#include "XOR.h"
#include "MOV.h"
#include "SPC.h"
#include "ADD.h"
using namespace std;

InstruccionFactory::InstruccionFactory() {
}

InstruccionFactory::InstruccionFactory(const InstruccionFactory& orig) {
}

InstruccionFactory::~InstruccionFactory() {
}

Instruccion* InstruccionFactory::getInstruccion(std::string c) {
    if (c != "") {
        c.erase(std::remove(c.begin(), c.end(), ' '), c.end());
        return validInstruccion(c);
    }
    return nullptr;
}

Instruccion* InstruccionFactory::validInstruccion(std::string c) {
    if (c == "ADD") {
        return new ADD();
    } else if (c == "AND") {
        return new AND();
    } else if (c == "BRA") {
        return new BRA();
    } else if (c == "CMP") {
        return new CMP();
    } else if (c == "JMP") {
        return new JMP();
    } else if (c == "JR") {
        return new JR();
    } else if (c == "LB") {
        return new LB();
    } else if (c == "LI") {
        return new LI();
    } else if (c == "LUI") {
        return new LUI();
    } else if (c == "SB") {
        return new SB();
    } else if (c == "SL") {
        return new SL();
    } else if (c == "SLT") {
        return new SLT();
    } else if (c == "SUB") {
        return new SUB();
    } else if (c == "MOV") {
        return new MOV();
    } else if (c == "XOR") {
        return new XOR();
    }else if (c == "SPC") {
        return new SPC();
    }
    return nullptr;
}
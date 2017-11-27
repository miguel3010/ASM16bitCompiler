#include "stdafx.h"
#include "Compilador.h"



#include <iostream>
#include <fstream>
#include "Compilador.h"
#include "Util.h"
#include "LabelManager.h"
#include "ParameterFactory.h"
#include "InstruccionFactory.h"
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Error.h"
#include "Parametro.h"

Compilador::Compilador() {
	cursor = 0;
	PC = 0;
}

Compilador::Compilador(const Compilador& orig) {
}

Compilador::~Compilador() {

	if (ASMCode) {
		delete[] ASMCode;

	}

}

void Compilador::reset() {

}

void Compilador::setASMCode(char* c, int l) {

	if (c && l > 0) {
		this->ASMCode = c;
		this->ASMLenght = l;
	}
}

bool Compilador::compilar() {
	char *c = readLine(); 
	 
		while (true) {		 
		if (c) {
			Compile(c); 			
			c = readLine();
		} else {
			break;
		}
	}
	
	LabelManager *lb = LabelManager::getInstance();
	if (lb->errorAnalyce()) {

		std::list<Error*> err = lb->getErrores();
		for (auto i : err) {
			errores.push_back((Error*) i);
		}
	}

	if (this->errores.size() > 0) {
		return false;
	} else {

		std::string out = filepath->url + "/" + filepath->fileName + ".o";

		ofstream myfile;
		myfile.open(out);
		for (Instruccion* o : instrucciones) {
			char *hex = nullptr;
			hex = o->getHex();
			myfile << hex;
			myfile << "\r\n";
			hex= nullptr;
		}
		myfile.close();
	}
	LabelManager* m = LabelManager::getInstance();
	m->reset();
	instrucciones.clear();
	return true;
}

std::list <Error*> Compilador::getErrorFlags() {

	return errores;
}

void Compilador::Compile(char* ASM) {
	std::string code(ASM);
	std::vector<std::string> ins = Util::Split(code, ' ');

	int size = ins.size();
	if (size >= 1 && size <= 4) {
		if (ins.size() == 1) {
			//Posible Etiqueta
			std::string e = ins.at(0);
			if (verifyLabel(e)) {
				ProcessLabel(e);
			} else {
				Error *e = new Error();
				string a(ASM);
				std::string error = "'" + a + "'" + " no es una instrucción Assembler valida";
				e->setdescripcion(error);
				e->setLinea(PC);
				this->errores.push_back(e);
			}
		} else {
			//Posible Instrucción comun
			ProcessInstruction(ins);
		}
	} else {
		Error *e = new Error();
		string a(ASM);
		std::string error = "'" + a + "'" + " no es una instrucción Assembler valida";
		e->setdescripcion(error);
		e->setLinea(PC);
		this->errores.push_back(e);
	}
	
}

bool Compilador::verifyLabel(std::string e) {
	char *c = (char*) e.c_str();
	if (c) {
		int l = Util::getLength(c);
		if (c[l - 1] == ':') {
			if (!Util::specialEti(c[0])) {
				int i = 1;
				while (i < l - 1) {
					if (Util::specialChar(c[i])) {
						return false;
					}
					i++;
				}
				return true;

			}

		}
	}
	return false;
}

char* Compilador::readLine() {

	if (ASMCode && cursor < ASMLenght) {
		int i = 0;
		//Desplazar cursor hasta la siguiente linea
		DesplazarCursor();
		//Cuenta los caracteres hasta el siguiente salto de linea        
		while (true) {
			if (i < ASMLenght && validateChar((char) ASMCode[i + cursor])) {
				i++;
			} else {
				break;
			}
		}

		if (i > 0) {
			char *subcadena = new char[i];
			subcadena[i] = 0;
			int h = i + cursor;
			int j = 0;
			while (cursor < h) {
				subcadena[j] = ASMCode[cursor];
				cursor++;
				j++;
			}
			return subcadena;
		}
	}
	return nullptr;
}

bool Compilador::validateChar(char a) {
	if (a != '\0') {
		if (a != '\r') {
			if (a != '\n') {
				return true;
			}
		}
	}
	return false;
}

void Compilador::DesplazarCursor() {
	while (cursor + 1 < ASMLenght && ASMCode[cursor] == '\r' && ASMCode[cursor + 1] == '\n') {
		cursor += 2;
	}
}

void Compilador::ProcessInstruction(std::vector<std::string> ins) {
	Parametro *p1 = nullptr;
	Parametro *p2 = nullptr;
	Parametro *p3 = nullptr;

	if (ins.at(0) == "OR"){
		ins.at(0).assign("MOV");
	}

	Instruccion *i = buildInstruction(ins.at(0));
	
	if (i != nullptr) {
		p1 = buildParameter(ins.at(1));
		if (ins.size() >= 3) {
			p2 = buildParameter(ins.at(2));
		}
		if (ins.size() == 4) {
			p3 = buildParameter(ins.at(3));
		}
		if (i->buildInstruccion(p1, p2, p3)) {
			this->instrucciones.push_back(i);
		} else {
			Error *e = nullptr;
			e = i->getError();
			if (e){
				e->setLinea(PC);
				this->errores.push_back(e);
			}
			

			//delete p1;
			//delete p2;
			//delete p3;
		}
	} else {
		Error *e = new Error();
		std::string error = "No se reconoce instrucción '" + ins.at(0) + "'";
		e->setdescripcion(error);
		e->setLinea(PC);
		this->errores.push_back(e);
	}
}

Instruccion* Compilador::buildInstruction(std::string ee) {
	InstruccionFactory *f = new InstruccionFactory();
	Instruccion *i = f->getInstruccion(ee);

	if (i == nullptr) {
		Error *e = new Error();
		std::string error = "El identificador " + ee + " no se reconoce como una instrucción válida.";
		e->setdescripcion(error);
		e->setLinea(PC);
		this->errores.push_back(e);
	}
	delete f;
	PC++;
	return i;

}

Parametro* Compilador::buildParameter(std::string ee) {
	Parametro *pa = nullptr;
	ParameterFactory *paf = new ParameterFactory();
	pa = paf->getParameter(ee);
	//delete paf;
	if (pa != nullptr) {
		if (pa->buildParametro((char*) ee.c_str())) {
			return pa;
		} else {
			this->errores.push_back(pa->getError());
		}
	} else {
		Error *e = new Error();
		std::string error = "El identificador " + ee + " no se reconoce como una instrucción válida.";
		e->setdescripcion(error);
		e->setLinea(PC);
		this->errores.push_back(e);
	}

	return nullptr;
}

void Compilador::ProcessLabel(std::string ins) {

	LabelManager *lm = LabelManager::getInstance();
	if (lm->RegistrarEtiruetaInstruccion(ins, PC)) {
		Etiqueta *e = lm->getEtiqueta(ins);
		instrucciones.push_back(e);
	} else {
		Error *err = new Error();
		err->setLinea(PC);
		string errr = "La etiqueta '" + ins + "' ya esta definida en este contexto.";
		err->setdescripcion(errr);
		errores.push_back(err);
	}
	PC++;
}

void Compilador::setURL(URL * url, std::string path) {
	int i = path.length() - 1;
	int k = path.find_last_of(".");
	int j = path.find_last_of("\\/");
	if (k - 1 - j > 0) {
		url->ext = path.substr(k + 1); // ext
		path.erase(k, i - 1);
		url->fileName = path.substr(j + 1); //filename
		path.erase(j + 1, path.length() - 1);
	} else {
		url->ext = "";
		url->fileName = "";
	}
	if (j > 0 | path.length() > 0) {

		url->url = path; //url
	} else {
		url->url = "";
	}
}

void Compilador::setURLToFile(std::string url) {
	reset();
	FILE *f = fopen(url.c_str(), "rb");
	if (f) {
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		fseek(f, 0, SEEK_SET); //same as rewind(f);

		char *string = (char*) malloc(fsize + 1);
		fread(string, fsize, 1, f);
		fclose(f);
		string[fsize] = 0;
		filepath = new Compilador::URL;
		setURL(filepath, url);
		setASMCode(string, (int) fsize);         
	}
}

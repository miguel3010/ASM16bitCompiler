#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Error.h"
#include "Parametro.h"
#include "Instruccion.h"

class Compilador {
public:
    typedef struct {
        std::string url;
        std::string fileName;
        std::string ext;
    } URL;
    
    Compilador();
    Compilador(const Compilador& orig);
    virtual ~Compilador();
    bool compilar();
    std::list <Error*> getErrorFlags();
    char* getProcessHex();
    
    void setURLToFile(std::string url);
private:
    std::list <Error*> errores;
    std::list<Instruccion*> instrucciones;
    void setASMCode(char *c, int l);
    void reset();
    char* ASMCode;
    int ASMLenght;
    int PC;
    int cursor;
    URL* filepath;
    char* readLine();
    bool validateChar(char a);
    void DesplazarCursor();
    void Compile(char* ASM);
    void ProcessLabel(std::string ins);
    void ProcessInstruction(std::vector<std::string> ins);
    bool verifyLabel(std::string e);
    void setURL(URL * url, std::string path);
    Instruccion* buildInstruction(std::string e);
    Parametro* buildParameter(std::string e);
};
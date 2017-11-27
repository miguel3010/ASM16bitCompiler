#pragma once

#include <vector> 
#include <stdlib.h>
#include<string.h>
#include<string>
#include <stdio.h>
using namespace std;

class Util {
public:
    Util();
    Util(const Util& orig);
    virtual ~Util();

    static std::vector<std::string> Split(std::string str, char regex);
    static int getLength(std::string c);
	static int getLength(char* c);
    static bool specialChar(char c);
    static bool specialEti(char c);
    static bool detecNumber(char c) ;
    static int  parseInt(char* s);
private:

};
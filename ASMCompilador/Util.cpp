#include "stdafx.h"
#include "Util.h"


#include <sstream>
#include <stdexcept>
#include "Util.h"

Util::Util() {
}

Util::Util(const Util& orig) {
}

Util::~Util() {
}

std::vector<std::string> Util::Split(std::string str, char regex) {
    std::vector<std::string> strings;
    std::string word;
    std::stringstream stream;
    stream.str(str);
    while (getline(stream, word, regex)) {
        strings.push_back(word);
    }
    return strings;
}

int Util::getLength(std::string c) {
    int ci = 0, i = 0;
    while (c[i] != '\0') {
        ci++;
        i++;
    }
    return ci;
}

int Util::getLength(char* c) {
	if(c){
    int ci = 0, i = 0;
    while (c[i] != '\0') {
        ci++;
        i++;
    }
	return ci;
	}
	return 0;
}

bool Util::specialChar(char c) {
    int i = 32;
    while (i < 48) {
        if ((int) c == i) {
            return true;
        }
        i++;
    }
    return false;
}

bool Util::specialEti(char c) {
    int i = 32;
    while (i < 65) {
        if ((int) c == i) {
            return true;
        }
        i++;
    }
    return false;
}

bool Util::detecNumber(char c) {
    int i = 0;
    int dn[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70};
    while (i < sizeof (dn) / sizeof (int)) {
        if ((int) c == dn[i]) {
            return true;
        }
        i++;
    }
    return false;
}

int Util::parseInt(char* s) {
    if ( s == nullptr || *s == '\0' )
        throw std::invalid_argument("null or empty string argument");

     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) 
         ++s;

     if ( *s == '\0')
        throw std::invalid_argument("sign character only.");

     int result = 0;
     while(*s)
     {
          if ( *s >= '0' && *s <= '9' )
          {
              result = result * 10  - (*s - '0');  //assume negative number
          }
          else
              throw std::invalid_argument("invalid input string");
          ++s;
     }
     return negate ? result : -result; //-result is positive!
}
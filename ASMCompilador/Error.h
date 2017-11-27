#pragma once
 
#include <string>
#include <string.h>


class Error {
public:
    Error();
    Error(const Error& orig);
    virtual ~Error();
    void setdescripcion(std::string e);
    std::string getDescripcion();
    int getLinea();
    void setLinea(int l);
    std::string ToString();
private:
    int PC;
    std::string desc;
};
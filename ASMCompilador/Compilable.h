#pragma once
class Compilable {
public:
    Compilable();
    Compilable(const Compilable& orig);
    virtual ~Compilable();
    virtual char* getHex() = 0;
private:

};
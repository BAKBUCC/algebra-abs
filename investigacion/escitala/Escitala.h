#ifndef ESCITALA_H
#define ESCITALA_H
#include <string>
#include <iostream>

using namespace std;

class Escitala
{
    public:
        string c,m,d;
        Escitala(string);
        string cifrado();
        string descifrado();
    private:
        int clave_columnas=4;
};

#endif // ESCITALA_H

#ifndef VERNAM_H
#define VERNAM_H

#include <iostream>

using namespace std;

class Vernam
{
private:
    string clave;
public:
    string alfabeto;
    string alfabeto2;
    Vernam(string);
    int DecimalBin(int);
    int BinDecimal(int);
    int XOR(int, int);
    string cifrar(string);
    string descifrar(string);
};

#endif // VERNAM_H

#include "vigenere.h"

int main() {
	string mensaje;
	string clave;
	std::cout << "ingrese el mensaje:";
	getline(cin, mensaje);
	std::cout << "ingrese la clave:";
	getline(cin,clave);
	Battista Giovani(mensaje, clave);
	Giovani.Belasso();
}
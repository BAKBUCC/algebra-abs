#include<iostream>
#include<string>
#include "roma.h"

int main() {
	string mensaje;
	cout << "ingresa el mensaje: ";
	getline(cin,mensaje);
	int desp;
	cout << "ingresa el despalzamiento: ";
	cin >> desp;
	caesar dominus(desp);
	dominus.casio(dominus.code(mensaje));
	
}
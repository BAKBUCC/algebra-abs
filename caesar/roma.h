#include <iostream>
#include <string>

using namespace std;

class caesar {
	int desp;
public:
	string abc;
	caesar(int des);
	string code(string men);
	void casio(string mensaje);
};

caesar::caesar(int des) {
	abc = "abcdefghijklmnopqrstuvwxyz";
	desp = des;
}

void caesar::casio(string mensaje) {
	int i = 0;
	int pos;
	int aux = 0;
	string::iterator prueba1;
	string descifrado;
	while (mensaje[i] != NULL) {
		mensaje[i] = tolower(mensaje[i]);
		aux = desp;
		pos = abc.find(mensaje[i]);
		if (pos >= 0) {
			prueba1 = abc.begin() + pos;
			while (aux != 0) {
				if (prueba1 == abc.begin() && aux >= 1) {
					prueba1 = abc.end();
				}
				prueba1 -= 1;
				aux -= 1;
			}
			descifrado.insert(descifrado.end(), *prueba1);
		}
		else {
			descifrado.insert(descifrado.end(), mensaje[i]);
		}
		i += 1;
	}
	cout << descifrado << endl;
}

string caesar::code(string men) {
	int i = 0;
	int pos;
	int aux = 0;
	string::iterator prueba1;
	string cifrado ;
	while (men[i] != NULL) {
		men[i] = tolower(men[i]);
		aux = desp;
		pos = abc.find(men[i]);
		if (pos >= 0) {
			prueba1 = abc.begin() + pos;
			while (aux != 0) {
				prueba1 += 1;
				if (prueba1 == abc.end()) {
					prueba1 = abc.begin();
				}
				aux -= 1;
			}
			cifrado.insert(cifrado.end(), *prueba1);
		}
		else {
			cifrado.insert(cifrado.end(), men[i]);
		}
		i += 1;
	}
	cout << cifrado << endl;
	pos = 0;
	aux = 0;
	return cifrado;
}

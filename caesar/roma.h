#include <iostream>
#include <string>

using namespace std;

class caesar {
	string mensaje;
	string abc;
	string cifrado;
	int desp;
	int aux;
	int pos;
public:
	caesar(string men, int des);
	void code();
	string Get_cifrado();
};

caesar::caesar(string men, int des) {
	mensaje = men;
	abc = "abcdefghijklmnopqrstuvwxyz";
	cifrado = "";
	desp = des;
	aux = 0;
	pos = 0;
}

void caesar::code() {
	int i = 0;
	string::iterator prueba1;
	while (mensaje[i] != NULL) {
		mensaje[i] = tolower(mensaje[i]);
		aux = desp;
		pos = abc.find(mensaje[i]);
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
			cifrado.insert(cifrado.end(), ' ');
		}
		i += 1;
	}
}

string caesar::Get_cifrado() {
	return cifrado;
}
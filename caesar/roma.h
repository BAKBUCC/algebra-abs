#include <iostream>
#include <string>

using namespace std;

class caesar {
	string mensaje;//emisor
	string abc;
	int desp;
public:
	caesar(string men, int des);
	void code();
};

caesar::caesar(string men, int des) {
	mensaje = men;
	abc = "abcdefghijklmnopqrstuvwxyz";
	desp = des;
}

void caesar::code() {
	int i = 0;
	int pos;
	int aux = 0;
	string::iterator prueba1;
	string cifrado = "";
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
			cifrado.insert(cifrado.end(), mensaje[i]);
		}
		i += 1;
	}
	cout << cifrado << endl;
	cifrado = "";
}

#include<iostream>
#include<string>

using namespace std;

class thomas {
	int rieles;
public:
	thomas(int code);
	string the_train(string palabra);
	string the_accident(string palabra);
};

thomas::thomas(int code) {
	rieles = code;
}

string thomas::the_train(string palabra) {
	int salto = 0;
	int aux = 0;
	int aux_rieles = rieles;
	string sms = "";
	int pediasure = 0;
	bool activar = false;
	bool ayuda = false;
	for (int i = 0; i < rieles; i++) {
		cout << aux_rieles  << endl;
		salto = i;
		activar = false;
		if (aux_rieles == 1) {
			aux_rieles = rieles;
			activar = false;
			ayuda = false;
		}
		if (aux_rieles % 2 == 0) {
			aux = (2 * aux_rieles) - 2;
		}
		else {
			aux = (aux_rieles - 1) * 2;
		}
		while (salto <= palabra.length() - 1) {
			if (!activar) {
				sms += palabra[salto];
				salto += aux;
				if (ayuda) {
					activar = true;
				}
			}
			else {
				sms += palabra[salto];
				salto += pediasure;
				activar = false;
			}
		}
		pediasure += 2;
		ayuda = true;
		aux_rieles -= 1;
		cout << sms << endl;
	}
	return sms;
}

string thomas::the_accident(string palabra) {
	string my_space = palabra;
	for (int i = 0; i < my_space.length(); i++) {
		my_space[i] = '_';
	}
	int pos = 0;
	int aux;
	int tumor = 0;
	int aux_rail = rieles;
	bool act = false;
	bool apoyo = false;
	int numero = 0;
	for (int i = 0; i < palabra.length(); i++) {
		if (aux_rail == 1) {
			aux_rail = rieles;
			act = false;
			apoyo = false;
		}
		if (aux_rail % 2 == 0) {
			aux = (2 * aux_rail) - 2;
			
		}
		else {
			aux = (aux_rail - 1) * 2;
		}
		cout << aux << endl << tumor << endl << pos << endl;
		if (apoyo == false) {
			my_space[pos] = palabra[i];
			pos += aux;
			if (act) {
				apoyo = true;
			}
			cout << "usado1" <<endl;
		}
		else {
			my_space[pos] = palabra[i];
			pos += tumor;
			apoyo = false;
			cout << "usado 2" << endl;
		}
		if (pos >= my_space.length()) {
			apoyo = false;
			numero += 1;
			tumor += 2;
			pos = numero;
			aux_rail -= 1;
			act = true;
		}
		cout << palabra[i] << endl;
		cout << my_space << endl;
	}
	return my_space;
}
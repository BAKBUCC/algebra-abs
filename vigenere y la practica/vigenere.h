#pragma once
#include <iostream>
#include <string>

using namespace std;

class Battista {
	string abc = "abcdefghijklmnñopqrstuvwxyz";
	int ASCII[55] = { 97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,32,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,44,46 };
	string mensaje;
	string clave;
public:
	Battista(string sms, string clv);
	void ahora_ascii(); //3b
	void inverted();//3b
	void Belasso();
	void vigenere();
	void aqui();//3e
	void quitar_w();//3e
	void complet();//3f
	void incomplet();//3f
	~Battista();
};

Battista::Battista(string sms, string clv) {
	mensaje = sms;
	clave = clv;
}

void Battista::ahora_ascii() {
	int pos_base = 0;
	int avance = 0;
	int i = 0;
	int j = 0;
	int letra;
	while (mensaje[i] != NULL) {
		letra = mensaje[i];
		for (int a = 0; a < 55; a++) {
			if (letra == ASCII[a]) {
				pos_base = a;
			}
		}
		letra = clave[j];
		for (int b = 0; b < 55; b++) {
			if (letra == ASCII[b]) {
				avance = b;
			}
		}
		while (avance > 0) {
			pos_base += 1;
			if (pos_base > abc.size() - 1) {
				pos_base = 0;
			}
			avance -= 1;
		}
		mensaje[i] = char(ASCII[pos_base]);
		if (clave[j + 1] == NULL) {
			j = 0;
		}
		else {
			j += 1;
		}
		i += 1;
	}
	std::cout << mensaje << endl;
}

void Battista::inverted() {
	int pos_base = 0;
	int avance = 0;
	int i = 0;
	int j = 0;
	int letra;
	while (mensaje[i] != NULL) {
		letra = mensaje[i];
		for (int a = 0; a < 55; a++) {
			if (letra == ASCII[a]) {
				pos_base = a;
			}
		}
		letra = clave[j];
		for (int b = 0; b < 55; b++) {
			if (letra == ASCII[b]) {
				avance = b;
			}
		}
		while (avance > 0) {
			pos_base -= 1;
			if (pos_base < 0) {
				pos_base = 54;
			}
			avance -= 1;
		}
		mensaje[i] = char(ASCII[pos_base]);
		if (clave[j + 1] == NULL) {
			j = 0;
		}
		else {
			j += 1;
		}
		i += 1;
	}
	std::cout << mensaje << endl;
}

void Battista::Belasso() {
	int pos_base = 0;
	int avance = 0;
	int i = 0;
	int j = 0;
	while (mensaje[i] != NULL) {
		pos_base = abc.find(mensaje[i]);
		avance = abc.find(clave[j]);
		while (avance > 0) {
			pos_base += 1;
			if (pos_base > abc.size() - 1) {
				pos_base = 0;
			}
			avance -= 1;
		}
		mensaje[i] = abc[pos_base];
		if (clave[j + 1] == NULL) {
			j = 0;
		}
		else {
			j += 1;
		}
		i += 1;
	}
	std::cout << mensaje << endl;
}

void Battista::vigenere() {
	int pos_base = 0;
	int avance = 0;
	int i = 0;
	int j = 0;
	while (mensaje[i] != NULL) {
		pos_base = abc.find(mensaje[i]);
		avance = abc.find(clave[j]);
		while (avance > 0) {
			pos_base -= 1;
			if (pos_base < 0) {
				pos_base = abc.size() - 1;
			}
			avance -= 1;
		}
		mensaje[i] = abc[pos_base];
		j += 1;
		if (clave[j]==NULL) {
			j = 0;
		}
		i += 1;
	}
	std::cout << mensaje << endl;
}

void Battista::aqui() {
	int i = 0;
	int cont = 10;
	while (mensaje[i] != NULL) {
		if (cont == 0) {
			mensaje.insert(i,"aqui");
			cont = 14;
		}
		cont -= 1;
		i += 1;
	}
	while (mensaje.size() % 4 != 0) {
		mensaje.insert(mensaje.size(), "W");
	}
	cout << mensaje << endl;
	Belasso();
}

void Battista::quitar_w() {
	vigenere();
	while (mensaje[mensaje.size() - 1] == 'W') {
		mensaje.erase(mensaje.size() - 1);
	}
	while (mensaje.find("aqui") != -1) {
		mensaje.erase(mensaje.find("aqui"), 4);
	}
	cout << mensaje;
}

void Battista::complet() {
	int pos_base = 0;
	int avance = 0;
	int i = 0;
	int j = 0;
	while (mensaje[i] != NULL) {
		pos_base = abc.find(mensaje[i]);
		avance = abc.find(clave[j]);
		clave += mensaje[i];
		while (avance > 0) {
			pos_base += 1;
			if (pos_base > abc.size() - 1) {
				pos_base = 0;
			}
			avance -= 1;
		}
		mensaje[i] = abc[pos_base];
		if (clave[j + 1] == NULL) {
			
			j = 0;
		}
		else {
			j += 1;
		}
		i += 1;
	}
	std::cout << mensaje << endl;
}

void Battista::incomplet() {
	int pos_base = 0;
	int avance = 0;
	int i = 0;
	int j = 0;
	int fase = 1;
	while (mensaje[i] != NULL) {
		if (fase == 1) {
			pos_base = abc.find(mensaje[i]);
			avance = abc.find(clave[j]);
			while (avance > 0) {
				pos_base -= 1;
				if (pos_base < 0) {
					pos_base = abc.size() - 1;
				}
				avance -= 1;
			}
			mensaje[i] = abc[pos_base];
			cout << mensaje << endl << clave << endl;
			clave += mensaje[i];
			j += 1;
			if (clave[j] == NULL) {
				j = 0;
			}
			i += 1;
		}
	}
	std::cout << mensaje << endl;
}

Battista::~Battista() {
	mensaje = "";
	clave = "";
}

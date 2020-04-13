#include<iostream>
#include<string>

using namespace std;

//estos son los ejercicios del 1 al 3

//la respuesta del ejercicio 2 es: El tamaño o la longitud de un objeto string es el numero de caracteres actualmente almacenados en el objeto string. La capacidad de un objeto string es el número de caracteres que se pueden almacenar en el objeto string sin necesidad de asignar más memoria

class Erase_una_vez {
	string plomo;
public:
	Erase_una_vez(string a);
	void Alquimia();
	void Crisopeya(char* lst, int aux);
	void Explotion(string objeto);
	void implotion(string objeto);
	~Erase_una_vez();
};

Erase_una_vez::Erase_una_vez(string a) {
	plomo = a;
}

Erase_una_vez::~Erase_una_vez() {
	plomo = "";
}

void Erase_una_vez::implotion(string objeto) {
	for (int i = 0; i < objeto.length(); i++) {
		objeto[i] = tolower(objeto[i]);
	}
	cout << objeto << endl;
}

void Erase_una_vez::Explotion(string objeto) {
	for (int i = 0; i < objeto.length(); i++) {
		objeto[i] = toupper(objeto[i]);
	}
	cout << objeto << endl;
}

void Erase_una_vez::Crisopeya(char* lst, int aux) {
	for (int i = 0; i < aux; i++) {
		plomo += lst[i];
	}
	cout << plomo << endl;
}

void Erase_una_vez::Alquimia() {
	char* oro;
	oro = new char[plomo.length() + 1];
	for (int i = 0; i < plomo.length(); i++) {
		oro[i] = plomo[i];
	}
	oro[plomo.length()] = NULL;
	cout << endl;
	int aux = 0;
	cout << oro;
	cout << endl;
	Crisopeya(oro, aux);
	delete[] oro;
	oro = NULL;
}
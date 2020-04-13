#include<iostream>
#include<string>

//ejercicio 5 :D

using namespace std;

class COVID {
public:
	void relleno(char var);
};

void COVID::relleno(char val) {
	int limite = 0;
	string descripcion = " ";
	descripcion[0] = val;
	while (limite < 999) {
		descripcion += descripcion[0];
		limite += 1;
	}
	cout << descripcion.size();
}
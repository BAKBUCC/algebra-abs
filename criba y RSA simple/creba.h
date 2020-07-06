#include"Afin.h"
#include<vector>
#include<time.h>

class criba {
	int limite;
	string no_primos;
	string primos;
	vector<bool> numeros;
public:
	criba(int lim);
	string result_primos();
	int prim();
};

criba::criba(int lim) {
	limite = lim;
	no_primos = " ";
	primos = "";
	for (int i = 0; i <= limite; i++) {
		numeros.push_back(false);
	}
}
string criba::result_primos() {
	int cont = 2;
	int aux_cont = cont;
	int doble_aux_cont = cont;;
	while (cont * cont <= limite) {
		if (no_primos.find(' ' + to_string(cont) + ' ') == -1) {
			primos += (to_string(cont) + ' ');
			cont += cont;
			while (cont <= limite) {
				if (no_primos.find(' ' + to_string(cont) + ' ') == -1) {
					no_primos += (to_string(cont) + ' ');
				}
				cont += doble_aux_cont;
			}
			cont = aux_cont;
			cont += 1;
			aux_cont += 1;
			doble_aux_cont += 1;
		}
		else {
			cont += 1;
			aux_cont += 1;
			doble_aux_cont += 1;
		}
	}
	while (cont < limite) {
		if (no_primos.find(' ' + to_string(cont) + ' ') == -1) {
			primos += (to_string(cont) + ' ');

		}
		cont += 1;
	}
	cout << primos << endl;
	return primos;
}

int criba::prim() {
	numeros[0] = true;
	numeros[1] = true;
	int aux;
	int pos;
	for (int i = 2; (i * i) <= limite; i++) {
		if (numeros[i] == false) {
			aux = i;
			pos = i;
			i += aux;
			while (i <= limite) {
				numeros[i] = true;
				i += aux;
			}
			i = pos;
		}
	}
	/*for (int i = 0; i <= limite; i++) {
		if (numeros[i] == false) {
			cout << i << " ";
		}
	}*/
	srand(time(NULL));
	int index = (rand() % limite) + 1;
	while (numeros[index] != false) {
		index = (rand() % limite) + 1;
	}
	return index;
}

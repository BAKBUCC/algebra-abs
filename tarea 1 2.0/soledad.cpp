#include<iostream>
#include<string>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include"Cuento.h"
#include"The_One.h"
#include"enfermedad.h"
#include"funcciones.h"

using namespace std;

void barajar(string letras, string mensaje, string caracter) {
	string::iterator andante, congelante;
	andante = mensaje.begin();
	congelante = mensaje.end();
	for (andante; andante != congelante; andante++) {
		int posicion = letras.find(*andante);
		*andante = caracter[posicion];
	}
	cout << mensaje << endl;
}

void desbarajar(string letras, string mensaje, string caracter) {
	string::iterator andante, congelante;
	andante = mensaje.begin();
	congelante = mensaje.end();
	for (andante; andante != congelante; andante++) {
		int posicion = caracter.find(*andante);
		*andante = letras[posicion];
	}
	cout << mensaje << endl;
}

void problema18_7() {
	string letras = "abcdefghijklmnopqrstuvwxyz";
	string::iterator andante = letras.begin() + 13;
	string caracter = string(andante, letras.end()) + string(letras.begin(), andante);
	string texto;
	cout << "ingresa el texto: " << endl;
	getline(cin, texto);
	barajar(letras, texto, caracter);
}

void ejercicio18_11() {
	string nombre, apellido;
	cout << "ingresa el nombre: ";
	cin >> nombre;
	cout << "ingresaa el apellid: ";
	cin >> apellido;
	string final = nombre + " " + apellido;
	cout << final;
}

void monigote(int fues) {
	if (fues == 1) {
		cout << "  0  " << endl;
	}
	if (fues == 2) {
		cout << "  0  " << endl;
		cout << " /| " << endl;
	}
	if (fues == 3) {
		cout << "  0  " << endl;
		cout << " /|\\ " << endl;
	}
	if (fues == 4) {
		cout << "  0  " << endl;
		cout << " /|\\ " << endl;
		cout << "  |  " << endl;
	}
	if (fues == 5) {
		cout << "  0  " << endl;
		cout << " /|\\ " << endl;
		cout << "  |  " << endl;
		cout << " /  " << endl;
	}
	if (fues == 6) {
		cout << "  0  " << endl;
		cout << " /|\\ " << endl;
		cout << "  |  " << endl;
		cout << " / \\" << endl;
	}
}


void cuelgate() {
	string palabra="logaritmo";
	string duplicado;
	string aux;
	string intento;
	int pos;
	//cout << "ingresa la palabra: ";
	//cin >> palabra;
	duplicado = palabra;
	aux = palabra;
	for (int i = 0; i < palabra.length(); i++) {
		duplicado[i] = 'X';
	}
	int aciertos = 0;
	int fue = 0;
	while (true) {
		cout << duplicado << endl;
		cout << "ingresa tu intento: ";
		cin >> intento;
		if (intento == palabra) {
			cout << "ganaste" << endl;
			cout << "quieres jugar otra vez?: [Y/n] ";
			string rpta;
			cin >> rpta;
			if (rpta == "n")
				break;
		}
		else {
			while (aux.find(intento[0]) != -1) {
				pos = aux.find(intento[0]);
				aux.replace(pos, 1, " ");
				duplicado[pos] = intento[0];
				aciertos += 1;
			}
			if (aciertos > 0) {
				cout << "continua" << endl;
			}
			else {
				fue += 1;
				monigote(fue);
			}
			if (fue == 7) {
				cout << "perdiste bro";
				cout << "quieres jugar otra vez?: [Y/n] ";
				string rpta;
				cin >> rpta;
				if (rpta == "n")
					break;
			}
			aciertos = 0;
			cout << endl;
			if (duplicado == palabra) {
				cout << "ganaste" << endl;
				cout << "quieres jugar otra vez?: [Y/n] ";
				string rpta;
				cin >> rpta;
				if (rpta == "n")
					break;
			}
		}
	}
}

void ejercicio18_19(string carne, string cuchillo) {
	carne.insert((carne.size() / 2), cuchillo);
	cout << carne;
}

/*void ejercicio18_21() {
	string frase = "paco-peco.pico:poco,puco";
	cout << frase << endl;
	for (int i = 0; i < frase.size(); i++) {
		if (frase[i] == '-' || frase[i] == '.' || frase[i] == ',' || frase[i] == ':') {
			frase[i] = ' ';
		}
	}
	char* list = new char[frase.size()];
	for (int i = 0; i < frase.size(); i++)list[i] = frase[i];
	char* token = strtok(list, " ");
	while (token != NULL) {
		cout << endl << token;
		token = strtok(NULL, " ");
	}
}*/

void contrario(string f) {
	string revez = f;
	int j = f.length()-1;
	for (int i = 0; i<f.size(); i += 1) {
		revez[j] = f[i];
		j--;
	}
	string::const_iterator andante = revez.begin();
	while (andante != revez.end()) {
		cout << *andante;
		andante += 1;
	}
}

void ejercicio18_27() {
	vector<string> list = {"2", "12", "23", "1"};
	int tam = list.size();
	for (int i = 0; i < tam - 1; i++) {
		int menor = i;
		for (int j = i; j < tam; j++) {
			if (list[j] < list[menor]) {
				menor = j;
			}
		}
		list[i].swap(list[menor]);
	}
	for (int i = 0; i < tam; i++) {
		cout << list[i] << endl;
	}
}

int main() {
	/*string nombre;
	cout << "ingresa una palabra: " << endl;;
	getline(cin,nombre);
	Erase_una_vez Alquimista(nombre);
	Alquimista.Alquimia();*/
	//cout << endl << "ingresa la prueba: " << endl;
	//getline(cin, nombre);
	//Alquimista.Explotion(nombre);
	//Alquimista.implotion(nombre);
	/*moonchild Iron_maiden;
	Iron_maiden.first_sin();
	Iron_maiden.fourth_sin();
	COVID diecinueve;
	diecinueve.relleno('a');*/
	/*string fras = "oe tas bn por que te pregunto si tas bn XD";
	string search = "tas";
	spell_words(fras,search);*/
	/*ahora_con_iteradores(fras);
	string carne = "gato";
	string cuchillo = "ti";
	carnicero(carne, cuchillo);*/
	/*string old = "no me mires no me mires no me no me no me mires";
	string objetivo = "mires";
	string bala = "toques";
	rplace(old, objetivo, bala);*/
	//palabra_mayor("primer", "primer");
	//neruda(5);
	//escamilla();
	//ejercicio18_11();
	cuelgate();
	//contrario("matame");
	//string frase = "Yo desaprobre el curso de Abstracta";
	//change(frase);
	//problema18_7();
	//ejercicio18_21();
	//ejercicio18_27();
	return 0;
}
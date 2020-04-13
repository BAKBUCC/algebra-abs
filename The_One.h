#include<iostream>
#include<string>

using namespace std;

class moonchild {
public:
	void first_sin();
	void second_sin(int a, int b);
	void third_sin(int a, int b);
	void fourth_sin();
};

//ejercicio 4 :D

void moonchild::fourth_sin() {
	cout << "ingresa el un numero(sera tratado como string): ";
	string a;
	cin >> a;
	cout << "ingresa el un numero(sera tratado como string): ";
	string b;
	cin >> b;
	int convertido = stoi(a);
	int infectado = stoi(b);
	second_sin(convertido, infectado);
}

void moonchild::third_sin(int a, int b) {
	string palabra = to_string(a * 2);
	string siguiente = to_string(b * 2);
	cout << palabra + siguiente << endl;
}

void moonchild::second_sin(int a, int b) {
	string palabra = to_string(a);
	string siguiente = to_string(b);
	cout << palabra + siguiente << endl;
	third_sin(a, b);
}

void moonchild::first_sin() {
	cout << "ingrese el primer numero: ";
	int primera;
	cin >> primera;
	cout << "ingresa el segundo numero: ";
	int segunda;
	cin >> segunda;
	second_sin(primera, segunda);
}
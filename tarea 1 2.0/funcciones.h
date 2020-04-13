#include<iostream>
#include<string>

using namespace std;

//ejercicio 6

void change(string cambiado) {
	string cosa = "aprobe";
	string objetivo = "desaprobre";
	int pos;
	pos = cambiado.find(objetivo);
	cambiado.replace(pos, objetivo.size(), cosa);
	cout << cambiado << endl;
}

//ejercicio 7

void spell_words(string a, string b) {
	cout << a << endl;
	int cont = 0;
	int pos;
	while (a.find(b) != -1) {
		pos = a.find(b);
		a.replace(pos, 1, " ");
		cont += 1;
	}
	cout << cont;
}

//ejercicio 8 y 9 

void ahora_con_iteradores(string frase) {
	string::const_iterator andante = frase.begin();
	while (andante != frase.end()) {
		cout << *andante;
		andante += 1;
	}

}

void carnicero(string carne, string cuchillo) {
	carne.insert((carne.size() / 2), cuchillo);
	cout << carne;
}

//ejercicio 10 y 11 post data: hice esto antes de leer el libro por eso no use funciones :D 

void rplace(string old, string objetivo, string bala) {
	int pos;
	while (true) {
		pos = old.find(objetivo);
		old.replace(pos,bala.size(), bala);
		cout << old << endl;
		if (old.find(objetivo) == -1) {
			break;
		}
 	}
}

void palabra_mayor(string primer, string segundo) {
	for (int i = 0; i < primer.size(); i++) {
		if (primer[i] > segundo[i]) {
			cout << primer;
			break;
		}
		else if (segundo[i] > primer[i]) {
			cout << segundo;
			break;
		}
		if (i == primer.size() - 1) {
			cout << "ninguno";
		}
	}
}

//ejercicio 12 y 13 de la practica

void neruda(int a) {
	srand(time(NULL));
	fstream poe("numeros.txt", ios::out);
	int num;
	while (a != 0) {
		num = 1 + rand() % 1000;
		poe << num;
		if (a > 1) {
			poe << endl;
		}
		a -= 1;
	}
	poe.close();
}

void escamilla() {
	fstream franco("numeros.txt", ios::in);
	string valor;
	int val;
	int result = 0;
	while (franco >> valor) {
		val = stoi(valor);
		result += val;
	}
	cout << result;
}


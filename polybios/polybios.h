#include<iostream>
#include<string>

using namespace std;

class polybios {
	string abc;
public:
	polybios();
	string chanfle(string palabra);//cifrar una palabra
	string deschanfle(string palabra);
};

polybios::polybios() {
	abc = "abcdefghijklmnñopqrstuvwxyz";
}

string polybios::chanfle(string palabra) {
	string msg = "";
	int x = 0;
	int y = 0;
	bool bisturi = false;
	for (int i = 0; i < palabra.length(); i++) {
		x = 0;
		y = 0;
		for (int j = 0; j < abc.length(); j++) {
			if (palabra[i] == ' ') {
				msg += ' ';
				break;
			}
			if (abc[j] == palabra[i]) {
				msg += abc[y];
				msg += abc[x];
				break;
			}
			if (abc[j] == 'i' || abc[j] == 'ñ') {
				x += 0;
			}
			else {
				x += 1;
			}
			if (x > 4) {
				x = 0;
				y += 1;
			}
		}
	}
	return msg;
}

string polybios::deschanfle(string palabra) {
	string sms = "";
	int indice = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < palabra.length() - 1; i += 2) {
		if (palabra[i] == ' ') {
			i += 1;
			sms += ' ';
		}
		x = abc.find(palabra[i]);
		y = abc.find(palabra[i + 1]);
		cout << x << " " << y << endl;
		indice = ((x * 5) + y);
		if (indice > 8 && indice < 12) {
			indice += 1;
		}
		else if (indice > 12) {
			indice += 2;
		}
		sms += abc[indice];
	}
	return sms;
}


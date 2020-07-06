#include "polybios.h"
#include"railfence.h"
#include "creba.h"

class RSA {
	string abc;
	long long int p, q;
	long long int N;
	long long int phi_N;
	long long int Clav_pub;
	long long int Clav_priv;
public:
	RSA();
	long long int get_N();
	long long int get_clv_priv();
	long long int cifrado(string palabra);
	long long int resto_chino(long long int pala);
	string descifrado(long long int palabra, long long int clv_priv, long long int Ne);
};

RSA::RSA() {
	abc = "abcdefghijklmnopqrstuvwxyz";
	criba crb(100000);
	p = crb.prim();
	q = crb.prim();
	while (p == q) {
		q = crb.prim();
	}
	N = p * q;
	phi_N = (p - 1) * (q - 1);
	Clav_pub = (rand() % phi_N + 1) + 1;
	while (euclides(Clav_pub, phi_N) != 1) {
		Clav_pub = (rand() % phi_N + 1) + 1;
	}
	Clav_priv = euclides_plus_e_inversa(Clav_pub, phi_N);
}

long long int RSA::get_N() {
	return N;
}

long long int RSA::get_clv_priv() {
	return Clav_priv;
}

long long int RSA::cifrado(string palabra) {
	string cfr = "";
	unsigned long long int pos = abc.find(palabra);
	long long int aux = Clav_pub;
	long long int pos_2;
	pos_2 = expo_mod(pos, Clav_pub, N);
	return pos_2;
}

string RSA::descifrado(long long int palabra, long long int clv_priv, long long int Ne) {
	int help = expo_mod(palabra, clv_priv, Ne);
	string lol = "";
	lol = abc[help];
	return lol;
}

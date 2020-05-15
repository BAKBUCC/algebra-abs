#include<iostream>
#include"NTL/ZZ.h"
#include<ctime>

using namespace std;
using namespace NTL;


ZZ alg_1(ZZ a, ZZ b) {
	ZZ cociente = a / b;
	ZZ residuo = a - cociente;
	if (residuo == 0) {
		return b;
	}
	else {
		a = b;
		b = residuo;
		return alg_1(a, b);
	}
}

ZZ alg_2(ZZ num, ZZ div) {
	ZZ cociente = num / div;
	ZZ residuo = num - cociente;
	if (residuo == 0) {
		return div;
	}
	else {
		if (residuo > (div / 2)) {
			residuo = div - residuo;
		}
		num = div;
		div = residuo;
		return alg_2(num, div);
	}
}

ZZ alg_3(ZZ a, ZZ b) {
	if (b == 0) {
		return a;
	}
	else {
		return alg_3(b, (a % b));
	}
}

ZZ mov_bits(ZZ a, ZZ b) {

	if (abs(b) > abs(a)) {
		return mov_bits(b, a);
	}
	if (b == 0) {
		return a;
	}
	if (a % 2 == 0 && b % 2 == 0) {
		return 2 * (mov_bits((a / 2), (b / 2)));
	}
	else if (a % 2 == 0 && b % 2 == 1) {
		return mov_bits(a / 2, b);
	}
	else if (a % 2 == 1 && b % 2 == 0) {
		return mov_bits(a, b / 2);
	}
	else {
		return mov_bits((abs(a) - abs(b)) / 2, b);
	}
}

ZZ algoritmo_5(ZZ a, ZZ b) {
	int g = 1;
	ZZ t;
	while (a % 2 == 0 && b % 2 == 0) {
		a /= 2;
		b /= 2;
		g *= 2;
	}
	while (a != 0) {
		while (a % 2 != 0) {
			a /= 2;
		}
		while (b % 2 != 0) {
			b /= 2;
		}
		t = (abs(a - b)) / 2;
		if (a >= b) {
			a = t;
		}
		else {
			b = t;
		}
	}
	return (g * b);
}

ZZ algoritmo_6(ZZ as, ZZ joker) {
	while (as != joker) {
		if (as > joker) {
			as -= joker;
		}
		else {
			joker -= as;
		}
	}
	return as;
}


int main() {
	unsigned t0, t1;
	ZZ a ;
	ZZ b ;
	cin >> a;
	cout << endl;
	cin >> b;
	t0 = clock();
	alg_1(a, b);
	t1 = clock();
	double time = (double(t1 - t0)/CLOCKS_PER_SEC);
	cout << alg_1(a, b) << endl;
	cout << time;

	t0 = clock();
	alg_2(a, b);
	t1 = clock();
	time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << alg_2(a, b) << endl;
	cout << time;

	t0 = clock();
	alg_3(a, b);
	t1 = clock();
	time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << alg_3(a, b) << endl;
	cout << time;

	t0 = clock();
	mov_bits(a, b);
	t1 = clock();
	time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << mov_bits(a, b) << endl;
	cout << time;

	t0 = clock();
	algoritmo_5(a, b);
	t1 = clock();
	time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << algoritmo_5(a, b) << endl;
	cout << time;

	t0 = clock();
	algoritmo_6(a, b);
	t1 = clock();
	time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << algoritmo_6(a, b) << endl;
	cout << time;
}
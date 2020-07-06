#include<iostream>
#include <vector>
#include "modulo.h"
using namespace std;

int euclides_plus_e_inversa(int numero_1, int numero_2) {
    int r_1 = numero_1;
    int r_2 = numero_2;
    int s_1 = 1;
    int s_2 = 0;
    int t_1 = 0;
    int t_2 = 1;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    while (r_2 > 0) {
        q = r_1 / r_2;
        r = r_1 % r_2;
        r_1 = r_2;
        r_2 = r;
        s = s_1 - (q * s_2);
        s_1 = s_2;
        s_2 = s;
        t = t_1 - (q * t_2);
        t_1 = t_2;
        t_2 = t;
    }
   // cout << "maximo comun multiplo: " << r_1 << endl << s_1 << endl << t_1 <<
        //endl;
    if (r_1 == 1) {
        if (s_1 > 0) {
           // cout << "inversa de " << numero_1 << " es: " << s_1 << endl;
            return s_1;
        }
        else {
            int aux = s_1 / numero_2;
            int residuo = s_1 - (numero_2 * aux);
            if (residuo < 0) {
                residuo += numero_2;
            }
           cout << "la inversa de " << numero_1 << " es: " << residuo << endl;
            return residuo;
        }
    }
    else {
        cout << "no tiene inversa";
        return 0;
    }
}

int euclides(long long int a,long long int b) {
    long long int q;
    long long int r_1 = a;
    long long int r_2 = b;
    long long int r;
    while (r_2 > 0) {
        q = r_1 / r_2;
        r = r_1 - (q * r_2);
        r_1 = r_2;
        r_2 = r;
    }
    return r_1;
}
long long int expo_mod(unsigned long long int a, unsigned long long int b, unsigned long long int c) {
    long long int exp = 1;
    unsigned long long int x = a % c;
    while (b > 0) {
        if (modulo(b,2)== 1) {
            exp = modulo((exp * x),c);
        }
        x = (x * x) % c;
        b = (b/2);
    }
    return exp;
}
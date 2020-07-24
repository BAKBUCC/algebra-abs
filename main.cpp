#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>
#include "NTL/ZZ.h"
#include <sstream>
#include <string>
#include <Windows.h>
#include "psapi.h"

using namespace NTL;
using namespace std;

class RSA_BLOQUES {
    ZZ p, q, N, e, d, phi_N; // e==calve publica
    ZZ Ne, D, NO, E;
    ZZ clv;
    int bt;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
public:
    RSA_BLOQUES(int bits);
    RSA_BLOQUES(ZZ Ne, ZZ clvp);
    RSA_BLOQUES(ZZ De, ZZ N, ZZ NN, ZZ Es);
    vector<ZZ> criba(ZZ mayor, ZZ menor);
    ZZ explosion_modular(ZZ base, ZZ exponente, ZZ mod);
    ZZ modulo(ZZ a, ZZ b);
    bool euclides(ZZ a, ZZ b);
    bool test_prim(ZZ numero);
    ZZ generar_primo(int bits);
    vector<ZZ> euclides_plus(ZZ a, ZZ b);
    ZZ inversa(ZZ e, ZZ N);
    string cifrar(string messenger);
    string descifrado(string msg);
};

RSA_BLOQUES::RSA_BLOQUES(ZZ N, ZZ De, ZZ NN, ZZ Es) {
    Ne = N;
    D = De;
    NO = NN;
    E = Es;
}

RSA_BLOQUES::RSA_BLOQUES(int bits) {
    srand(time(NULL));
    ZZ aux = ZZ(1);
    ZZ aux_aux = aux;
    bt = bits;
    bits /= 2;
    while (bits > 1) {
        aux *= 2;
        bits -= 1;
    }
    vector<ZZ> primos_random = criba(aux - 1, aux / 2);
    p = primos_random[rand()%primos_random.size()];
    q = primos_random[rand() % primos_random.size()];
    while (q == p ) {
        q= primos_random[rand() % primos_random.size()];
    }
    N = p * q;
    phi_N = (p - 1) * (q - 1);
    e = primos_random[rand() % primos_random.size()];
    while (!euclides(e,phi_N)) {
        e = primos_random[rand() % primos_random.size()];
    }
    d = inversa(e, phi_N);
    std::cout << N << endl << e << endl;
    cout << d << endl;
}
RSA_BLOQUES::RSA_BLOQUES(ZZ Ne, ZZ clvp) {
    N = Ne;
    clv = clvp;
}
vector<ZZ> RSA_BLOQUES::criba(ZZ mayor, ZZ menor) {
    ZZ intervalo = (mayor - menor) + 1;
    int primos = 2;
    bool agregar = true;
    vector<ZZ> numero_primos;
    while (menor <= mayor) {
        agregar = true;
        primos = 2;
        while (primos * primos < mayor) {
            if (menor % primos == 0) {
                agregar = false;
                break;
            }
            primos += 1;
        }
        if (agregar) {
            numero_primos.push_back(menor);
        }
        menor += 1;
    }
    return numero_primos;
}
ZZ RSA_BLOQUES::explosion_modular(ZZ base, ZZ exponente, ZZ mod) {
    ZZ exp = ZZ(1);
    while (exponente > 0) {
        if (modulo(exponente, ZZ(2)) == 1) {
            exp = modulo((exp * base), mod);
        }
        base = (base * base) % mod;
        exponente = (exponente / 2);
    }
    return exp;
}
ZZ RSA_BLOQUES::modulo(ZZ a, ZZ b) {
    ZZ aux = a / b;
    ZZ residuo = a - (aux * b);
    if (residuo < 0) {
        residuo += b;
    }
    return residuo;
}
bool RSA_BLOQUES::euclides(ZZ a, ZZ b) {
    ZZ q;
    ZZ r_1 = a;
    ZZ r_2 = b;
    ZZ r;
    while (r_2 > 0) {
        q = r_1 / r_2;
        r = r_1 - (q * r_2);
        r_1 = r_2;
        r_2 = r;
    }
    if (r_1 == 1) {
        return true;
    }
    else {
        return false;
    }
}
ZZ RSA_BLOQUES::generar_primo(int bits) {
   srand(time(NULL));
    vector<ZZ> premo;
    int exponente = bt / 2;
    ZZ numero = ZZ(2);
    ZZ aux = numero;
    while (exponente > 0) {
        numero *= aux;
        exponente -= 1;
    }
    premo = criba(numero - 1, numero / 2);
    int random = rand() % premo.size();
    return premo[random];
    
}

bool RSA_BLOQUES::test_prim(ZZ numero) {
    ZZ aux = ZZ(8);
    if (explosion_modular(aux, numero, numero) != aux) {
        return false;
    }
    return true;
}

vector<ZZ> RSA_BLOQUES::euclides_plus(ZZ a, ZZ b) {
    vector<ZZ> invrt;
    ZZ r_1 = a; // residuo
    ZZ r_2 = b;
    ZZ s_1 = ZZ(1); // x
    ZZ s_2 = ZZ(0);
    ZZ t_1 = ZZ(0); // y
    ZZ t_2 = ZZ(1);
    ZZ q = ZZ(0);
    ZZ r = ZZ(0);
    ZZ s = ZZ(0);
    ZZ t = ZZ(0);
    bool rtn = false;
    while (!rtn) {
        invrt.clear();
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
        if (r_1 == 1) {
            if (s_1 < 0) {
                s_1 += b;
            }
            rtn = true;
        }
        else {
            r_1 = generar_primo(16);
        }
    }
    invrt.push_back(s_1);
    invrt.push_back(t_1);
    invrt.push_back(r_1);
    return invrt;
}
ZZ RSA_BLOQUES::inversa(ZZ e, ZZ N) {
    vector<ZZ> resultados;
    resultados = euclides_plus(e, N);
    return resultados[0];
}
string RSA_BLOQUES::cifrar(string messenger) {
    string aux_abc = to_string(abc.size());
    int cifras_abc = aux_abc.size();
    stringstream valor_grande;
    valor_grande << Ne;
    string cifras = valor_grande.str();
    int cifras_N = cifras.size();
    int bloques_N = cifras.size() - 1;
    int pos;
    ZZ valor = ZZ(0);
    string aux_numeros = "";
    string numeros = "";
    string bloques = "";
    string msg = "";
    for (int i = 0; i < messenger.size(); i++) {
        aux_numeros = "";
        pos = abc.find(messenger[i]);
        aux_numeros += to_string(pos);
        while (aux_numeros.size() < cifras_abc) {
            aux_numeros = ('0' + aux_numeros);
        }
        numeros += aux_numeros;
    }
    cout << numeros << endl;
    aux_numeros = to_string(abc.find('w'));
    while (numeros.size() % bloques_N != 0) {
        numeros += aux_numeros[numeros.size() % 2];
    }
    cout << numeros << endl;
    vector<string> block;
    for(int i = 0; i < numeros.size(); i++){
        bloques += numeros[i];
        if(bloques.size() == bloques_N){
            block.push_back(bloques);
            bloques = "";
        }
    }
    for(int i = 0; i < block.size(); i++){
        string aux = block[i];
        ZZ ayuda = ZZ(1);
        for (int j = aux.size() - 1; j >= 0; j--) {
            int help = to_int(aux[j]) - '0';
            valor += (help * ayuda);
            ayuda *= 10;
        }
        valor = explosion_modular(valor, D, Ne);
        stringstream valor_grande;
        valor_grande << valor;
        bloques = valor_grande.str();
        while (bloques.size() < cifras_N) {
            bloques = ('0' + bloques);
        }
        msg += bloques;
        valor = ZZ(0);
    }
    cout << msg << endl;
    numeros = msg;
    msg = "";
    bloques = "";
    stringstream valor_grande_2;
    valor_grande_2 << NO;
    cifras = valor_grande_2.str();
    cifras_N = cifras.size();
    bloques_N = cifras_N - 1;
    aux_numeros = to_string(abc.find('w'));
    while (numeros.size() % bloques_N != 0) {
        numeros += aux_numeros[numeros.size() % 2];
    }
    cout << numeros << endl;
    block.clear();
    for(int i = 0; i < numeros.size(); i++){
        bloques += numeros[i];
        if(bloques.size() == bloques_N){
            block.push_back(bloques);
            bloques = "";
        }
    }
    for(int i = 0; i < block.size(); i++){
        string aux = block[i];
        ZZ ayuda = ZZ(1);
        for (int j = aux.size() - 1; j >= 0; j--) {
            int help = to_int(aux[j]) - '0';
            valor += (help * ayuda);
            ayuda *= 10;
        }
        valor = explosion_modular(valor, E, NO);
        stringstream valor_grande;
        valor_grande << valor;
        bloques = valor_grande.str();
        while (bloques.size() < cifras_N) {
            bloques = ('0' + bloques);
        }
        msg += bloques;
        valor = ZZ(0);
    }
    cout << msg << endl;
    return msg;
}
string RSA_BLOQUES::descifrado(string msg) {
    string aux_abc = to_string(abc.size());
    int cifras_abc = aux_abc.size();
    stringstream valor_grande;
    valor_grande << Ne;
    string cifras = valor_grande.str();
    int cifras_N = cifras.size();
    int bloques_N = cifras.size() - 1;
    int pos;
    string bloque = "";
    string numero = "";
    string result = "";
    vector<string>cuadrados;
    ZZ valor = ZZ(0);
    for(int i = 0; i < msg.size(); i++){
        bloque += msg[i];
        if(bloque.size() == cifras_N){
            cuadrados.push_back(bloque);
            bloque = "";
        }
    }
    for(int i = 0; i < cuadrados.size(); i++){
        bloque = cuadrados[i];
        ZZ ayuda = ZZ(1);
        for (int j = bloque.size() - 1; j >= 0; j--) {
            int help = to_int(bloque[j]) - '0';
            valor += (help * ayuda);
            ayuda *= 10;
        }
        valor = explosion_modular(valor, D, Ne);
        stringstream valor_grande;
        valor_grande << valor;
        bloque = valor_grande.str();
        while (bloque.size() < bloques_N) {
            bloque = ('0' + bloque);
        }
        result += bloque;
        valor = ZZ(0);
    }
    cout << result << endl;
    msg = result;
    result = "";
    bloque = "";
    stringstream valor_grande_2;
    valor_grande_2 << NO;
    cifras = valor_grande_2.str();
    cifras_N = cifras.size();
    bloques_N = cifras_N - 1;
    cuadrados.clear();
    for(int i = 0; i < msg.size(); i++){
        bloque += msg[i];
        if(bloque.size() == cifras_N){
            cuadrados.push_back(bloque);
            bloque = "";
        }
    }

    for(int i = 0; i < cuadrados.size(); i++){
        bloque = cuadrados[i];
        ZZ ayuda = ZZ(1);
        for (int j = bloque.size() - 1; j >= 0; j--) {
            int help = to_int(bloque[j]) - '0';
            valor += (help * ayuda);
            ayuda *= 10;
        }
        valor = explosion_modular(valor, E, NO);
        stringstream valor_grande;
        valor_grande << valor;
        bloque = valor_grande.str();
        while (bloque.size() < bloques_N) {
            bloque = ('0' + bloque);
        }
        result += bloque;
        valor = ZZ(0);
    }

    cout << result << endl;
    vector<string>letras;
    bloque = "";
    for(int i = 0; i < result.size(); i++){
        bloque += result[i];
        if(bloque.size() == cifras_abc){
            letras.push_back(bloque);
            bloque = "";
        }
    }
    result = "";
    for(int i = 0; i < letras.size(); i ++){
        pos = stoi(letras[i]);
        result += (abc[pos]);
    }

    return result;
}
ZZ modulo(ZZ a, ZZ n)
{
    if (n <= 0)
        return ZZ(0);
    if (a < n && a >= 0)
        return a;
    ZZ q(a / n);
    if (a < 0)
        q -= 1;
    return  a - (q * n);
};

int main() {
    ZZ Ne, prv, NO, clvp;
    string mensaje;
    cout << "ingresa tu N y su e y su N y tu d: : " << endl;
    cin >> Ne;
    cin >> prv;
    cin >> NO;
    cin >> clvp;
    RSA_BLOQUES no_firma(Ne, prv, NO, clvp);
    cout << "ingrese el mensaje: " << endl;
    cin.ignore();
    getline(cin, mensaje);
    string no_firmado = no_firma.descifrado(mensaje);
    cout << no_firmado;
    }
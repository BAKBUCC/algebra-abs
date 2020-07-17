#include<iostream>
#include<sstream>
#include"NTL/ZZ.h"
#include<ctime>
#include<vector>
#include<math.h>
#include<ctime>

using namespace NTL;
using namespace std;

class RSA_BLOQUES {
    ZZ p, q, N, e, d, phi_N; // e==calve publica
    ZZ clv;
    int bt;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
public:
    RSA_BLOQUES(int bits);
    RSA_BLOQUES(ZZ Ne, ZZ clvp);
    vector<ZZ> criba(ZZ mayor, ZZ menor);
    ZZ explosion_modular(ZZ base, ZZ exponente, ZZ mod);
    ZZ modulo(ZZ a, ZZ b);
    bool euclides(ZZ a, ZZ b);
    ZZ generar_primo();
    vector<ZZ> euclides_plus(ZZ a, ZZ b);
    ZZ inversa(ZZ e, ZZ N);
    string cifrar(string messenger);
    string descifrado(string msg);
};
RSA_BLOQUES::RSA_BLOQUES(int bits) {
    srand(time(NULL));
    ZZ aux = ZZ(1);
    ZZ aux_aux = aux;
    bt = bits;
    bits /= 2;
    while (bits > 1) {
        cout << aux << endl;
        aux *= 2;
        bits -= 1;
    }
    vector<ZZ> primos_random = criba(aux - 1, aux / 2);
    p = primos_random[(rand() % primos_random.size())];
    q = primos_random[(rand() % primos_random.size())];
    while (q == p) {
        q = primos_random[(rand() % primos_random.size())];
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
    /*vector<ZZ> residuos_validos;
    string binario = "";
    ZZ aux = exponente;
    while (aux > 0) {
        if (aux % 2 == 0) {
            binario += '0';
        }
        else {
            binario += '1';
        }
        aux /= 2;
    }
    ZZ result = base;
    aux = exponente;
    int index = 0;
    while (aux > 0) {
        if (binario[index] == '1') {
            residuos_validos.push_back(result);
        }
        result *= result;
        result = result % mod;
        aux /= 2;
        index += 1;
    }
    index = 2;
    ZZ residuo = residuos_validos[0] * residuos_validos[1];
    residuo = residuo % mod;
    for (index; index < residuos_validos.size(); index++) {
        residuo *= residuos_validos[index];
        residuo = residuo % mod;
    }
    residuos_validos.clear();
    return residuo;*/
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
ZZ RSA_BLOQUES::generar_primo() {
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
            r_1 = generar_primo();
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
    int cifras = 0;
    int cifras_abc = 0;
    int aux_abc = abc.size();
    int pos;
    ZZ valor = ZZ(0);
    string aux_numeros = "";
    string numeros = "";
    string bloques = "";
    string msg = "";
    ZZ aux = N;
    while (aux > 0) {
        aux /= 10;
        cifras += 1;
    }
    while (aux_abc >= 1) {
        aux_abc /= 10;
        cifras_abc += 1;
    }
    for (int i = 0; i < messenger.size(); i++) {
        aux_numeros = "";
        pos = abc.find(messenger[i]);
        aux_numeros += to_string(pos);
        while (aux_numeros.size() < cifras_abc) {
            aux_numeros = ('0' + aux_numeros);
        }
        numeros += aux_numeros;
    }
    while (numeros.size() % (cifras - 1) != 0) {
        aux_numeros = to_string(abc.find(' '));
        numeros += aux_numeros;
    }
    for (int i = 0; i < numeros.length(); i++) {
        bloques += numeros[i];
        if (bloques.size() == cifras - 1) {
            ZZ ayuda = to_ZZ(1);
            for (int j = bloques.size() - 1; j >= 0; j--) {
                int help = to_int(bloques[j]) - '0';
                valor += (help * ayuda);
                ayuda *= 10;
            }
            valor = explosion_modular(valor, clv, N);
            stringstream valor_grande;
            valor_grande << valor;
            bloques = valor_grande.str();
            while (bloques.length() < cifras) {
                bloques = ('0' + bloques);
            }
            msg += bloques;
            bloques = "";
            valor = 0;
            ayuda = 1;
        }
    }
    
    return msg;
}
string RSA_BLOQUES::descifrado(string msg) {
    int cifras = 0;
    int aux_pos = 0;
    string bloque = "";
    string numero = "";
    string pos = "";
    string result = "";
    ZZ val = ZZ(0);
    ZZ aux = N;
    while (aux > 0) {
        aux /= 10;
        cifras += 1;
    }
    for (int i = 0; i < msg.size(); i++) {
        bloque += msg[i];
        if (bloque.size() == cifras) {
            cout << bloque << endl;
            ZZ ayuda = ZZ(1);
            for (int j = bloque.size() - 1; j >= 0; j--) {
                int help = to_int(bloque[j]) - '0';
                val += (help * ayuda);
                ayuda *= 10;
            }
            cout << val << endl;
            val = explosion_modular(val, clv, N);
            cout << val << endl;
            stringstream valor_grande;
            valor_grande << val;
            bloque = valor_grande.str();
            while (bloque.size() < (cifras - 1)) {
                bloque = ('0' + bloque);
            }
            numero += bloque;
            bloque = "";
            val = ZZ(0);
            ayuda = 1;
        }
    }
    cout << numero << endl;
    int cifras_abc = 0;
    int aux_abc = abc.size();
    while (aux_abc > 0) {
        aux_abc /= 10;
        cifras_abc += 1;
    }
    for (int i = 0; i < numero.length(); i++) {
        pos += numero[i];
        if (pos.size() == cifras_abc) {
            aux_pos = stoi(pos);
            result += abc[aux_pos];
            pos = "";
        }
    }
    return result;
}
int main() {
    int bits;
    cout << "1. generar clave publica y N." << endl << "2. cifrar." << endl << "3. descifrar." << endl;
    cout << "ingresa el numero de bits: " << endl;
    cin >> bits;
    RSA_BLOQUES tetris(bits);
    ZZ Ne, prv;
    cout << "ingresa tu N y tu d: " << endl;
    cin >> Ne;
    cin >> prv;
    RSA_BLOQUES firma(Ne, prv);
    string mensaje;
    cout << "ingrese el mensaje: " << endl;
    cin.ignore();
    getline(cin, mensaje);
    string firmado = firma.cifrar(mensaje);
    ZZ N, e;
    cout << "ingresa su n y tu e" << endl;
    cin >> N;
    cin >> e;
    RSA_BLOQUES emisor(N, e);
    string mensaje_cifrado = emisor.cifrar(firmado);
    cout << mensaje_cifrado << endl;
    cout << "ingresa tu N y tu d: " << endl;
    cin >> Ne;
    cin >> prv;
    RSA_BLOQUES no_firma(Ne, prv);
    cout << "ingrese el mensaje: " << endl;
    cin.ignore();
    getline(cin, mensaje);
    string no_firmado = no_firma.descifrado(mensaje);

    cout << "ingresa su n y tu e" << endl;
    cin >> N;
    cin >> e;
    RSA_BLOQUES receptor(N, e);
    string mensaje_descifrado = receptor.descifrado(no_firmado);
    cout << mensaje_descifrado;
}
#include "Vernam.h"
#include "math.h"

string ASCCI();
int Pot(int x, int y);

Vernam::Vernam(string _clave)
{
    clave = _clave;
    alfabeto = ASCCI();
    alfabeto2 = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}
int Vernam::DecimalBin(int a){
     int v = 0;
     for (int x = 1; a != 0 ;x *= 10){
        int residuo = a%2;
        v = v + residuo*x;
        a /= 2;
        }
    return v%Pot(10,5);
}
int Vernam::BinDecimal(int a){
    int v = 0;
    for (int x = 1; a != 0;x *= 2){
        int residuo = a%10;
        v = v + residuo*x;
        a /= 10;
    }
    return v;
}
int Vernam::XOR(int a,int b){
    int dig = 5;
    int v = 0;
    for (int i = 0; i < dig ;i++){
        if(a%10 == b%10){
            v += 0;
        }
        else{v += 1*Pot(10,i);}
        a /= 10;
        b /= 10;
        //cout << v<<endl;
    }
    return v;//%Pot(10,5);
}
string Vernam::cifrar(string mensaje){
    string mensajeCifrado;
    for(int i = 0 ; i < mensaje.length() ; i++){
        int posicionM = alfabeto.find( mensaje[i]);
        int posicionC = alfabeto.find( clave[i]);
        int Binam = XOR(DecimalBin(posicionM),DecimalBin(posicionC));
        cout << mensaje[i]<< " = "<< DecimalBin(posicionM)<< " & "<< clave[i]<< " = "<< DecimalBin(posicionC)<<endl;
        cout << DecimalBin(posicionM)<< " XOR "<< DecimalBin(posicionC)<< " = "<< Binam <<endl;
        for(int j = 65; j < 91 ;j++){
            cout << Binam <<" "<< DecimalBin(alfabeto.find(alfabeto[j]))<<" " << alfabeto[j] <<endl;
            if(Binam == DecimalBin(alfabeto.find(alfabeto[j]))){
                mensajeCifrado += alfabeto[j];
                cout << mensajeCifrado<<endl;
                break;
            }
        }
    }
    return mensajeCifrado;
}

string ASCCI(){
    string ASCCI;
    for(int i = 0 ; i < 127; i ++){
            char c = static_cast<int>(i);
            ASCCI += c;
    }
    return ASCCI;
}
int Pot(int x, int y){
    int n = 1;
    while(y > 0){
        n *= x;
        y--;
    }
    return n;
}

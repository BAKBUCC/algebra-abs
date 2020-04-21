#include "Playfair.h"
#include <iostream>

Playfair::Playfair()
{
   string clave="GEODA";
   cargar_matriz(clave);

}
void Playfair::cargar_matriz(string clave){

    string abecedario = "ABCDEFGHIKLMNOPQRSTUWVXYZ";
    string aux=abecedario;
    string matriz[5];
    matriz[0]=clave;

    for(int i=0;i<5;i++){
        int pos = aux.find(matriz[0][i]);
        aux.replace(pos,1,"");
    }
    int k=0;
    for(int i=1;i<5;i++){
        string aux_1;
        for(int j=0;j<5;j++)
            aux_1+=aux[k++];
        matriz[i]=aux_1;
    }
    for(int i=0;i<5;i++){
        cout << matriz[i]<< endl;
    }
}
bool Playfair::regla_1(string par){

        string m1 = "";
        m1+=par[0];
        string m2 = "";
        m2+=par[1];

        int i=0;
        int pos = matriz[i++].find(m1);

        for(;pos==string::npos;i++)
            pos = matriz[i].find(m1);

        int pos_1 = matriz[i].find(m2);
        if(pos_1==string::npos)
            return false;
        return true;

}
bool Playfair::regla_2(string par){

        string m1 = "";
        m1+=par[0];
        string m2 = "";
        m2+=par[1];

        int i=0;
        int pos = matriz[i++].find(m1);

        for(;pos==string::npos;i++)
            pos = matriz[i].find(m1);
        for(i=0;i<5;i++){
            string aux = "";
            aux+=matriz[i][pos];
            if(aux==m2)
                return true;
        }
        return false;

}
string Playfair::regla_3(string par){

        string m1 = "";
        m1+=par[0];
        string m2 = "";
        m2+=par[1];
        string cifrado="";

        int x_1=0;
        int y_1 = matriz[x_1++].find(m1);

        for(;y_1==string::npos;x_1++)
            y_1 = matriz[x_1].find(m1);

        int x_2=0;
        int y_2 = matriz[x_2++].find(m2);

        for(;y_2==string::npos;x_2++)
            y_2 = matriz[x_2].find(m2);

        cifrado+=matriz[x_1][y_2];
        cifrado+=matriz[x_2][y_1];

        return cifrado;
}
string Playfair::regla_4(string){
}

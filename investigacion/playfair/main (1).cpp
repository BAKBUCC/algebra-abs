#include <iostream>

using namespace std;


int main()
{
    string abecedario = "ABCDEFGHIKLMNOPQRSTUWVXYZ";
    string aux=abecedario;
    string clave[5];
    clave[0]="BOB";


    for(int i=0;i<5;i++){
        int pos = aux.find(clave[0][i]);
        aux.replace(pos,1,"");
    }
    int k=0;
    for(int i=1;i<5;i++){
        string aux_1;
        for(int j=0;j<5;j++){
            aux_1+=aux[k];
            k++;
        }
        clave[i]=aux_1;
    }

    for(int i=0;i<5;i++){
        cout << clave[i]<< endl;
    }
  /*
    void cifrar(){

        if(regla_1&&regla_2)
            regla_4;
        else if(regla_1)
            ejecutar_regla_1();
        else if(regla_2)
            ejecutar_regla_2();
        else
            regla_3;

    }
    */


    return 0;
}

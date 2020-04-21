#include <iostream>
#include <Vernam.h>

using namespace std;

int main()
{
    string clave = "MXUZOPT";
    Vernam emisor(clave);
    string cif = emisor.cifrar("TARINGA");
    cout << "Descifrado: " << endl << endl ;
    string descif = emisor.cifrar(cif);
    return 0;
}

#include "Escitala.h"

int main()
{
    string str,c,d;
    cout<<"coloque mensaje: ";
    getline(cin,str);
    cout<<endl;
    Escitala emisor(str);
    c=emisor.cifrado();
    cout<<"\nmensaje cifrado: "<<"\""<<c<<"\""<<endl;

    Escitala receptor(c);
    d=receptor.descifrado();
    cout<<"\n\nmensaje descifrado: "<<"\""<<d<<"\""<<endl;

}

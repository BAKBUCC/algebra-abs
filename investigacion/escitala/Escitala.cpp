#include "Escitala.h"

Escitala::Escitala(string str)
{
    m=str;
    if(m.length()%clave_columnas!=0)
    {
        m.resize(m.length()+(clave_columnas-(m.length()%clave_columnas)));
    }
    c.resize(m.length());
    d.resize(m.length());
}

string Escitala::cifrado()
{
    int l=0;
    for(int i=0;i<clave_columnas; i++)
    {
        for(int unsigned j=0; j<m.length(); l++)
        {
            c[l]=m[i+j];
            j+=clave_columnas;
        }
    }
    return c;
}

string Escitala::descifrado()
{
    int l=0;
    for(int unsigned i=0;i<m.length()/clave_columnas; i++)
    {
        for(int unsigned j=0; j<m.length(); l++)
        {
            d[l]=m[i+j];
            j+=m.length()/clave_columnas;
        }
    }
    return d;
}

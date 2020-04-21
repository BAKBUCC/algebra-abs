#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <string>

using namespace std;

class Playfair
{
    public:

        Playfair();
        void cargar_matriz(string);
        bool regla_1(string);
        bool regla_2(string);
        string regla_3(string);
        string regla_4(string);


    protected:

    private:
        string matriz[5];
};

#endif // PLAYFAIR_H

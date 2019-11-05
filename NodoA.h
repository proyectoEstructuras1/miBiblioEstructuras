#ifndef NODOA_H
#define NODOA_H

#include <iostream>
using namespace std;

class NodoA{
private:
    NodoA* izq;
    int dato;
    NodoA* der;
public:
    NodoA(void);
    NodoA(NodoA* i, int da, NodoA* d);
    void pideDatos(void);
    void muestraDato(void);
    void muestraDatos(void);
    NodoA* dameIzq(void);
    void modificaIzq(NodoA* i);
    int dameDato(void);
    void modificaDato(int da);
    NodoA* dameDer(void);
    void modificaDer(NodoA* d);
};


#endif // NODOA_H

#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo{
private:
    int dato;
    Nodo* sig;
public:
    Nodo(void);
    Nodo(int d, Nodo* s);
    void muestraDatos(void);
    void muestraDato(void);
    void pideDatos(void);
    int dameDato(void);
    void modificaDato(int d);
    Nodo* dameSig(void);
    void modificaSig(Nodo* s);
};

#endif // NODO_H

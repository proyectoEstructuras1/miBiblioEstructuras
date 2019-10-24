#ifndef NODOC_H
#define NODOC_H


#include <iostream>
#include "Libro.h"
using namespace std;
class NodoL{
private:
    Libro dato;
    NodoL* sig;
public:
    NodoL(void);
    NodoL(Libro d, NodoL* s);
    void muestraDatos(void);
    void muestraDato(void);
    void pideDatos(void);
    Libro dameDato(void);
    void modificaDato(Libro d);
    NodoL* dameSig(void);
    void modificaSig(NodoL* s);
};


#endif // NODOC_H

#ifndef NODOC_H
#define NODOC_H


#include <iostream>
#include "Contacto.h"
using namespace std;
class NodoC{
private:
    Contacto dato;
    NodoC* sig;
public:
    NodoC(void);
    NodoC(Contacto d, NodoC* s);
    void muestraDatos(void);
    void muestraDato(void);
    void pideDatos(void);
    Contacto dameDato(void);
    void modificaDato(Contacto d);
    NodoC* dameSig(void);
    void modificaSig(NodoC* s);
};


#endif // NODOC_H

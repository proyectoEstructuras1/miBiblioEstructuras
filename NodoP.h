#ifndef NODOP_H
#define NODOP_H


#include <iostream>
#include "Termino.h"
using namespace std;
class NodoP{
private:
    Termino dato;
    NodoP* sig;
public:
    NodoP(void);
    NodoP(Termino d, NodoP* s);
    void muestraDatos(void);
    void muestraDato(void);
    void pideDatos(void);
    Termino dameDato(void);
    void modificaDato(Termino d);
    NodoP* dameSig(void);
    void modificaSig(NodoP* s);
};

#endif // NODOP_H

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include "NodoA.h"
using namespace std;
class Arbol{
private:
    NodoA* raiz;
    void muestraPre(NodoA* r);
    void muestraIn(NodoA* r);
    void muestraPos(NodoA* r);
public:
    Arbol(NodoA* r);
    ~Arbol(void);
    void muestraPre(void);
    void muestraIn(void);
    void muestraPos(void);
};

#endif // ARBOL_H

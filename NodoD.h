#ifndef NODOD_H
#define NODOD_H

#include <iostream>
#include "Nodo.h"
using namespace std;

class NodoD : public Nodo{
private:
    NodoD* pre;
public:
    NodoD(void);
    NodoD(NodoD* p, int d, Nodo* s);
    void muestraDato(void);
    void muestraDatos(void);
    NodoD* damePre(void);
    void modificaPre(NodoD* p);
};

#endif // NODOD_H

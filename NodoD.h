#ifndef NODOD_H
#define NODOD_H

#include <iostream>
using namespace std;

class NodoD{
private:
    NodoD* pre;
    int dato;
    NodoD* sig;
public:
    NodoD(void);
    NodoD(NodoD* p, int d, NodoD* s);
    void pideDatos(void);
    void muestraDato(void);
    void muestraDatos(void);
    NodoD* damePre(void);
    void modificaPre(NodoD* p);
    int dameDato(void);
    void modificaDato(int d);
    NodoD* dameSig(void);
    void modificaSig(NodoD* s);
};

#endif // NODOD_H

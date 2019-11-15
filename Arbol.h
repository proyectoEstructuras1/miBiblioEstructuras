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
    void insertaNodo(NodoA* r, int d);
    void eliminaArbol(NodoA* r);
    bool buscaNodo(NodoA* r, int d);
    int cuentaNodos(NodoA* r);
    int profundidadDelArbol(NodoA* r, int pP);
    bool eliminaNodo(NodoA* nP,NodoA* r,int d);
public:
    Arbol(void);
    ~Arbol(void);
    void muestraPre(void);
    void muestraIn(void);
    void muestraPos(void);
    void insertaNodo(int d);
    void eliminaArbol(void);
    bool buscaNodo(int d);
    int cuentaNodos(void);
    int profundidadDelArbol(void);
    bool eliminaNodo(int d);
};

#endif // ARBOL_H


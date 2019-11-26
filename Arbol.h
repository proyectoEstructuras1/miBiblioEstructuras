#ifndef ARBOLP_H
#define ARBOLP_H
#include<iostream>
#include"NodoA.h"


using namespace std;
class ArbolP
{
private:
    NodoA* raiz;
    void muestraPre(NodoA* r);
    void muestraPos(NodoA* r);
    void muestraIn (NodoA* r);
    void insertaNodo(NodoA* r, Producto d);
    void eliminaArbol(NodoA* r);
    bool buscaNodo(NodoA* r, int d);
    int cuentaNodos(NodoA* r);
    int profundidadDelArbol(NodoA* r, int pP);
    bool eliminaSubarbol(NodoA* nP,NodoA* r,int d);
    bool eliminaRama(NodoA* nP,NodoA* r,int d);
    bool eliminaNodo(NodoA* nP,NodoA* r,int d);
    void traeMenorNodo(NodoA* nP,NodoA* r,NodoA* aqui);

public:
    ArbolP(void);
    ~ArbolP(void);
    void muestraPre(void);
    void muestraPos(void);
    void muestraIn (void);
    void insertaNodo(Producto d);
    void eliminaArbol(void);
    bool buscaNodo(int d);
    int cuentaNodos(void);
    int profundidadDelArbol(void);
    bool eliminaSubarbol(int d);
    bool eliminaNodo(int d);


};

#endif // ARBOLP_H

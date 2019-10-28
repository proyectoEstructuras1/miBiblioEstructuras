#ifndef LISTAD_H
#define LISTAD_H

#include <iostream>
#include "NodoD.h"
using namespace std;
class ListaD{
private:
    NodoD* ini;
    NodoD* fin;
    NodoD* buscaNodo(int d);
public:
    ListaD(void);
    ~ListaD(void);
    bool estaVacia(void);
    void insertaNodo(int d);
    bool eliminaNodo(int d);
    bool buscaNodo(void);
    void muestraIniFin(void);
    void muestraFinIni(void);
    void eliminaLista(void);
};

#endif // LISTAD_H
